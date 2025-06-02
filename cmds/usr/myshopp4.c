#include <ansi.h>

#define MYSHOP_DIR	"/clone/tianji1/"//yuanbao

inherit F_CLEAN_UP;

mapping mtypes = ([
	"�̳�":"������",
]);

int main(object me, string arg)
{
	string str,*all_file,file,price,type,*types;
	int i,tianji1,value;
	object ob;
	int amount;

	all_file = list_dirs(MYSHOP_DIR);

	if(!sizeof(all_file))
		return notify_fail("����̳�������"HIG""NOR"��Ʒ���ۡ���\n");

	if (! arg)
	{
	 str = ZJOBLONG"��Ŀǰ��"+me->query("tianji1")+"����㣬��ѡ�����빺���"HIG""NOR"���ߣ�\n"ZJOBACTS2+ZJMENUF(3,3,8,32); 	
		for(i=0;i<sizeof(all_file);i++)
		{
			file = MYSHOP_DIR+all_file[i];
			if(file_size(file)<0) continue;
			if(file->query("no_shop")) continue;
			tianji1 = file->query("tianji1");
			price = tianji1?(tianji1+"�����"):(MONEY_D->money_str(file->query("value")));
			str += sprintf("%s"ZJBR"%s:myshopp4 look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if(arg=="type")
	{
		str = ZJOBLONG"��Ŀǰ��"+me->query("tianji1")+"����㣬��ѡ�����빺��ĵ������\n"ZJOBACTS2+ZJMENUF(3,3,8,32);
		types = sort_array(keys(mtypes),(:strcmp:));
		for(i=0;i<sizeof(types);i++)
		{
			str += sprintf("%s:myshopp4 type %s"ZJSEP,types[i],types[i]);
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
		str = ZJOBLONG"��Ŀǰ��"+me->query("tianji1")+"����㣬��ѡ�����빺���"HIG+types[i]+NOR"����ߣ�\n"ZJOBACTS2+ZJMENUF(3,3,8,32);
		for(i=0;i<sizeof(all_file);i++)
		{
			file = MYSHOP_DIR+mtypes[type]+"/"+all_file[i];
			if(file_size(file)<0) continue;
			if(file->query("no_shop")) continue;
			tianji1 = file->query("tianji1");
			price = tianji1?(tianji1+"�����"):(MONEY_D->money_str(file->query("value")));
			str += sprintf("%s"ZJBR"%s:myshopp4 look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		tianji1 = file->query("tianji1");
		price = tianji1?(tianji1+"�����"):(MONEY_D->money_str(file->query("value")));
		str = ZJOBLONG+"��"+file->query("name")+"�������۸�"+price+NOR+ZJBR"һһһһһһһһһһһһһһһһһһһһһһһ"ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "����1��:myshopp4 buy 1 "+file+ZJSEP"��������:myshopp4 buy "+file+"\n";
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if (sscanf(file, "%d %s", amount, file) != 2)
		{
			if(file_size(file)<0||strsrch(file,MYSHOP_DIR)!=0)
				return notify_fail(HIM"û��������ߣ���"NOR"\n");
			write(INPUTTXT("��������ٸ�"+file->query("name")+"��"ZJBR"��ȷ����ı����ռ��㹻��","myshopp4 buy $txt# "+file)+"\n");
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

		tianji1 = file->query("tianji1");
		if(!value=file->query("base_value"))
			value = file->query("value");
		if(!tianji1&&!value)
			return notify_fail(HIM"����ʧ�ܣ���"NOR"\n");

		if(tianji1)
		{
			if(!me->query("tianji1")||me->query("tianji1")<(tianji1*amount))
				return notify_fail(HIM"�������㲻�㣡��"NOR"\n");
			me->add("tianji1",-tianji1*amount);
			log_file("pay/tianji", sprintf("%s:%s(%s)����%d����㣬�������̳ǹ���%d��%s(%s)��\n",
				ctime(time()),me->query("name"),me->query("id"),tianji1*amount,amount,file->query("name"),file->query("id")));
			me->add("zjvip/yuanbao_used",tianji1*amount);
		}
		else
		{
			if(!MONEY_D->player_pay(me, value * amount))
				return notify_fail(HIM"���Ǯû��ô���ˣ���"NOR"\n");
			log_file("pay/tianji", sprintf("%s:%s(%s)����%s���������̳ǹ���%d��%s��\n",
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
