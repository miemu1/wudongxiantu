#define MYSHOP_DIR	"/clone/heixin_shop/"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,*all_file,file,price,type,*types;
	int i,yuan_bao,value;
	object ob;
	int amount;
	string banghui;

	all_file = list_dirs(MYSHOP_DIR);

	if(!sizeof(all_file))
		return notify_fail("�̳���������Ʒ���ۡ�\n");

	if (! arg)
	{
		str = ZJOBLONG"��Ŀǰ��"+me->query("yuan_bao")+"ͨ������ѡ�����빺��ĵ��ߣ�\n"ZJOBACTS2+ZJMENUF(4,4,8,30);
		for(i=0;i<sizeof(all_file);i++)
		{
			file = MYSHOP_DIR+all_file[i];
			if(file_size(file)<0) continue;
			if(file->query("no_shop")) continue;
			yuan_bao = file->query("yuanbao");
			price = yuan_bao + "ͨ��";
			str += sprintf("%s"ZJBR"%s:test look %s"ZJSEP,file->query("name"),price,file);
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		yuan_bao = file->query("yuanbao");
		price = yuan_bao+"ͨ��";
		str = ZJOBLONG+"��"+file->query("name")+"�������۸�"+price+NOR+ZJBR"һһһһһһһһһһһһһһһһһһһһһһһ"ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "����1��:test buy 1 "+file+ZJSEP"��������:test buy "+file+"\n";
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if (sscanf(file, "%d %s", amount, file) != 2)
		{
			write(INPUTTXT("��������ٸ�"+file->query("name")+"��"ZJBR"��ȷ����ı����ռ��㹻��","test buy $txt# "+file)+"\n");
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

		yuan_bao = file->query("yuanbao");
		
		if(!yuan_bao)
		{
			write (HIM"����ʧ�ܣ���"NOR"\n");
			return 0;
		}

		if(yuan_bao)
		{		
			if(!me->query("yuan_bao")||me->query("yuan_bao")<(yuan_bao*amount))
			{
				write("���ͨ�����㡣\n");
				return 0;
			}
		
			me->add("yuan_bao",-yuan_bao*amount);
			log_file("pay/heixin_shop", sprintf("%s:%s(%s)����%dͨ�����������̳ǹ���%d��%s(%s)��\n",
				ctime(time()),me->query("name"),me->query("id"),yuan_bao*amount,amount,file->query("name"),file->query("id")));
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