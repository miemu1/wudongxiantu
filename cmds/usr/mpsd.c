#include <ansi.h>

#define MYSHOP_DIR	"/clone/menpai/"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,*all_file,file,price,type,*types;
	int i,gongxian,value;
	object ob;
	mixed today;
	int amount;

	all_file = list_dirs(MYSHOP_DIR);

	if(!sizeof(all_file))
		return notify_fail("�̳���������Ʒ���ۡ�\n");
	
	if (! arg)
	{
		str = ZJOBLONG"��Ŀǰ��"+me->query("gongxian")+"���ף���ѡ������һ��ĵ��ߣ�\n"ZJOBACTS2+ZJMENUF(3,4,8,32);
		for(i=0;i<sizeof(all_file);i++)
		{
			file = MYSHOP_DIR+all_file[i];
			if(file_size(file)<0) continue;
			gongxian = file->query("gongxian");
			if(gongxian)
			{
				gongxian = gongxian;
				if(gongxian<1) gongxian = 1;
			}
			price = gongxian?(gongxian+"����"):((file->query("gongxian")));
			str += sprintf("%s"ZJBR"%s:mpsd look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		gongxian = file->query("gongxian");
			if(gongxian)
			{
				gongxian = gongxian;
				if(gongxian<1) gongxian = 1;
			}
		price = gongxian?(gongxian+"����"):((file->query("gongxian")));
		str = ZJOBLONG+"��"+file->query("name")+"�������۸�"+price+NOR+ZJBR"һһһһһһһһһһһһһһһһһһһһһһһ"ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "�һ�1��:mpsd buy 1 "+file+ZJSEP"�����һ�:mpsd buy "+file+"\n";
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if (sscanf(file, "%d %s", amount, file) != 2)
		{
			if(file_size(file)<0||strsrch(file,MYSHOP_DIR)!=0)
				return notify_fail(HIM"û��������ߣ���"NOR"\n");

			write(INPUTTXT("����һ����ٸ�"+file->query("name")+"��"ZJBR"��ȷ����ı����ռ��㹻��","mpsd buy $txt# "+file)+"\n");
			return 1;
		}

		if(file_size(file)<0||strsrch(file,MYSHOP_DIR)!=0)
			return notify_fail(HIM"û��������ߣ���"NOR"\n");
		if(amount<1)
			return notify_fail(HIM"��Ҫ����ٸ�����"NOR"\n");
		if(amount>999)
			return notify_fail(HIM"��Ҫ����ٸ�����"NOR"\n");
		if(!file->query_amount()&&amount>10)
			return notify_fail(HIM"���ɵ�����Ʒһ�������10������"NOR"\n");

		gongxian = file->query("gongxian");
			if(gongxian)
			{
				gongxian = gongxian;
				if(gongxian<1) gongxian = 1;
			}
		if(!value=file->query("base_value"))
			value = file->query("value");
		if(!gongxian&&!value)
			return notify_fail(HIM"�һ�ʧ�ܣ���"NOR"\n");

		if(gongxian)
		{
			if(!me->query("gongxian")||me->query("gongxian")<(gongxian*amount))
				return notify_fail(HIM"��Ĺ��ײ���!!"NOR"\n");
			me->add("gongxian",-gongxian*amount);
			log_file("pay/mpsd", sprintf("%s:%s(%s)ʹ����%d���ף��ӹ����̳Ƕһ�%d��%s(%s)��\n",
				ctime(time()),me->query("name"),me->query("id"),gongxian*amount,amount,file->query("name"),file->query("id")));
			me->add("zjvip/gongxian_used",gongxian*amount);
		}
		else
		{
			if(!MONEY_D->player_pay(me, value * amount))
				return notify_fail(HIM"������ɹ���û��ô���ˣ���"NOR"\n");
			log_file("pay/mpsd", sprintf("%s:%s(%s)����%s���������̳Ƕһ�%d��%s��\n",
				ctime(time()),me->query("name"),me->query("id"),MONEY_D->money_str(value*amount),amount,file->query("name")));
		}
		if(file->query_amount())
		{
			ob = new(file);
			ob->set_amount(amount);
			write("����̳��гɹ��һ���"+ob->short()+"��"NOR"\n");
			ob->move(me,1);
		}
		else
		{
			for(i=0;i<amount;i++)
			{
				ob = new(file);
				ob->move(me,1);
			}
			write("����̳��гɹ��һ���"+amount+ob->query("unit")+ob->short()+"��"NOR"\n");
		}
		if(file->query("max_buy"))
		{
			me->add("buy_max/"+file->query("id"),amount);
		}
		return 1;
	}
	else
		return notify_fail(HIM"�����ʲô����"NOR"\n");

	return 1;
}

int help(object me)
{
     write(@HELP

�����̳ǡ�

HELP
    );
    return 1;
}
