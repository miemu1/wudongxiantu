#include <ansi.h>

#define MYSHOP_DIR	"/clone/vip2/shimen"

inherit F_CLEAN_UP;

mapping mtypes = ([
	"�̳�":"������",
]);

int main(object me, string arg)
{
	string str,*all_file,file,price,type,*types;
	int i,yuanbao,value;
	object ob;
	int amount;

	all_file = list_dirs(MYSHOP_DIR);

	if(!sizeof(all_file))
		return notify_fail("�̳�������"HIG"��"NOR"����Ʒ���ۡ���\n");

	if (! arg)
	{
	 str = ZJOBLONG"��Ŀǰ��"+me->query("gongxian")+"ʦ�Ź��ף���ѡ�����빺���"HIG"��"NOR"����ߣ�\n"ZJOBACTS2+ZJMENUF(4,4,8,37); 	
		for(i=0;i<sizeof(all_file);i++)
		{
			file = MYSHOP_DIR+all_file[i];
			if(file_size(file)<0) continue;
			if(file->query("no_shop")) continue;
			yuanbao = file->query("yuanbao");
			price = yuanbao?(yuanbao+"ʦ�Ź���"):(MONEY_D->money_str(file->query("value")));
			str += sprintf("%s"ZJBR"%s:myshop2 look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if(arg=="type")
	{
		str = ZJOBLONG"��Ŀǰ��"+me->query("yuanbao")+"ʦ�Ź��ף���ѡ�����빺��ĵ������\n"ZJOBACTS2+ZJMENUF(4,4,8,37);
		types = sort_array(keys(mtypes),(:strcmp:));
		for(i=0;i<sizeof(types);i++)
		{
			str += sprintf("%s:myshop2 type %s"ZJSEP,types[i],types[i]);
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"type %s",type)==1)
	{
		if(!mtypes[type])
			return notify_fail("�̳�������"HIG+type+NOR"����Ʒ���ۡ�\n");
		all_file = list_dirs(MYSHOP_DIR+mtypes[type]+"/");
		if(!sizeof(all_file))
			return notify_fail("�̳�������"HIG+type+NOR"����Ʒ���ۡ�\n");
		str = ZJOBLONG"��Ŀǰ��"+me->query("yuanbao")+"ʦ�Ź��ף���ѡ�����빺���"HIG+types[i]+NOR"����ߣ�\n"ZJOBACTS2+ZJMENUF(4,4,8,37);
		for(i=0;i<sizeof(all_file);i++)
		{
			file = MYSHOP_DIR+mtypes[type]+"/"+all_file[i];
			if(file_size(file)<0) continue;
			if(file->query("no_shop")) continue;
			yuanbao = file->query("yuanbao");
			price = yuanbao?(yuanbao+"ʦ�Ź���"):(MONEY_D->money_str(file->query("value")));
			str += sprintf("%s"ZJBR"%s:myshop2 look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		yuanbao = file->query("yuanbao");
		price = yuanbao?(yuanbao+"ʦ�Ź���"):(MONEY_D->money_str(file->query("value")));
		str = ZJOBLONG+"��"+file->query("name")+"�������۸�"+price+NOR+ZJBR"һһһһһһһһһһһһһһһһһһһһһһһ"ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "����1��:myshop2 buy 1 "+file+ZJSEP"��������:myshop2 buy "+file+"\n";
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if (sscanf(file, "%d %s", amount, file) != 2)
		{
			if(file_size(file)<0||strsrch(file,MYSHOP_DIR)!=0)
				return notify_fail(HIM"û��������ߣ���"NOR"\n");
			write(INPUTTXT("��������ٸ�"+file->query("name")+"��"ZJBR"��ȷ����ı����ռ��㹻��","myshop2 buy $txt# "+file)+"\n");
			return 1;
		}

		if(file_size(file)<0||strsrch(file,MYSHOP_DIR)!=0)
			return notify_fail(HIM"û��������ߣ���"NOR"\n");

		if(file->query("no_shop"))
			return notify_fail(HIM"���¼���Ʒ���޷����򣡣�"NOR"\n");
		if(amount<1)
			return notify_fail(HIM"��Ҫ����ٸ�����"NOR"\n");
		if(!file->query_amount()&&amount>10)
			return notify_fail(HIM"���ɵ�����Ʒһ�������10������"NOR"\n");
		else if(amount>999)
			return notify_fail(HIM"һ�������999������"NOR"\n");

		yuanbao = file->query("yuanbao");
		if(!value=file->query("base_value"))
			value = file->query("value");
		if(!yuanbao&&!value)
			return notify_fail(HIM"����ʧ�ܣ���"NOR"\n");

		if(yuanbao)
		{
			if(!me->query("gongxian")||me->query("gongxian")<(yuanbao*amount))
				return notify_fail(HIM"��ĵ�ȯ���㣡��"NOR"\n");
			me->add("gongxian",-yuanbao*amount);
			log_file("pay/myshop2", sprintf("%s:%s(%s)����%d��ȯ���������̳ǹ���%d��%s(%s)��\n",
				ctime(time()),me->query("name"),me->query("id"),yuanbao*amount,amount,file->query("name"),file->query("id")));
			me->add("zjvip/yuanbao_used",yuanbao*amount);
		}
		else
		{
			if(!MONEY_D->player_pay(me, value * amount))
				return notify_fail(HIM"���Ǯû��ô���ˣ���"NOR"\n");
			log_file("pay/myshop2", sprintf("%s:%s(%s)����%s���������̳ǹ���%d��%s��\n",
				ctime(time()),me->query("name"),me->query("id"),MONEY_D->money_str(value*amount),amount,file->query("name")));
		}
		if(file->query_amount())
		{
			ob = new(file);
			ob->set_amount(amount);
			write("����̳��гɹ�����"+ob->short()+"��"NOR"\n");
			ob->move(me,1);
		}
		else
		{
			for(i=0;i<amount;i++)
			{
				ob = new(file);
				ob->move(me,1);
			}
			write("����̳��гɹ�����"+amount+ob->query("unit")+ob->short()+"��"NOR"\n");
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
