#include <ansi.h>
#include <localtime.h>

inherit NPC;
int do_shimen();
int do_chaxun();
int do_chaxun1();
void create()
{
	set_name(HIR"����ү"NOR,({"caishen"}));
	set("gender","����");
	set("long","СͶ�ʣ���ر���");
	set("per",20);
	set("age",15);
	set("combat_exp",100);
	set("inquiry", ([
                "1.ѡ������" : (: do_shimen :),
                "2.��ȡ����" : (: do_chaxun :),
                "3.��ѯ����" : (: do_chaxun1 :),
        ]));
	setup();
}
init ()
{
	add_action("do_choose","choose");
	add_action("do_choose1","choose1");
	add_action("do_choose2","choose2");
	add_action("do_choose3","choose3");
	add_action("do_choose4","choose4");

}


int do_shimen()
{
	string str;
			str = ZJOBLONG+ZJSIZE(30)+HIG"��������Ͷ��2000��ʯ������7��ÿ��"HIR"450"HIG"��ʯ"NOR+ZJBR+ZJSIZE(30)+HIG"�м�����Ͷ��5000��ʯ������7��ÿ��"HIR"1000"HIG"��ʯ"NOR+ZJBR+ZJSIZE(30)+HIG"�߼�����Ͷ��10000��ʯ������7��ÿ��"HIR"2200"HIG"��ʯ"NOR+ZJBR+ZJSIZE(30)+HIG"�ؼ�����Ͷ��20000��ʯ������7��ÿ��"HIR"4300"HIG"��ʯ"NOR+ZJBR+HIG"��ѡ��"+NOR+"\n"+ZJOBACTS2+ZJMENUF(1,1,8,28);
			str += HIY"�ֶ�����ѡ������:choose"+ZJSEP;

			write(str+"\n");
		return 1;
}
int do_chaxun()//������ȡ
{
	string str;
			str = ZJOBLONG+ZJSIZE(30)+HIG"������������7��ÿ����ȡ"HIR"450"HIG"��ʯ"NOR+ZJBR+ZJSIZE(30)+HIG"�м���������7��ÿ����ȡ"HIR"1000"HIG"��ʯ"NOR+ZJBR+ZJSIZE(30)+HIG"�߼���������7��ÿ����ȡ"HIR"2200"HIG"��ʯ"NOR+ZJBR+ZJSIZE(30)+HIG"�ؼ���������7��ÿ����ȡ"HIR"4300"HIG"��ʯ"NOR+ZJBR+HIG"��ѡ��"+NOR+"\n"+ZJOBACTS2+ZJMENUF(2,2,8,30);
			str += HIY"��ȡ��������:choose1 1"+ZJSEP;
			str += HIY"��ȡ�м�����:choose2 1"+ZJSEP;
			str += HIY"��ȡ�߼�����:choose3 1"+ZJSEP;
			str += HIY"��ȡ�ؼ�����:choose4 1"+ZJSEP;

			write(str+"\n");
		return 1;
}
int do_chaxun1(string arg)//�����ѯ
{
	int flag;
	string str;
	object ob1,ob2;
	object me = this_player();
		if(me->is_fighting())
	{tell_object(me,"��������ս����\n");
		return 1;}
		if(me->is_busy())
	{tell_object(me,"����æ��\n");
		return 1;}

    if(me->query("jijin/ss1")==1)
	{
       tell_object(me,HIG"�㵱ǰ����ĳ�������ʣ��������£�\n" +
		HIC"ÿ����ȡ��"HIW+chinese_number(450) + "��ʯ\n" +
        HIC"ʣ��������"HIW+chinese_number(7 - me->query("jijin/lingqu1")) + "��\n" +
        NOR);		
	}else	{tell_object(me,ZJSIZE(26)+HIR"����δ�����������\n"+NOR);
		}
    if(me->query("jijin/ss2")==1)
	{
       tell_object(me,HIG"�㵱ǰ������м�����ʣ��������£�\n" +
		HIC"ÿ����ȡ��"HIW+chinese_number(1000) + "��ʯ\n" +
        HIC"ʣ��������"HIW+chinese_number(7 - me->query("jijin/lingqu2")) + "��\n" +
        NOR);		
	}else	{tell_object(me,ZJSIZE(26)+HIR"����δ�����м�����\n"+NOR);
		}
    if(me->query("jijin/ss3")==1)
	{
       tell_object(me,HIG"�㵱ǰ����ĸ߼�����ʣ��������£�\n" +
		HIC"ÿ����ȡ��"HIW+chinese_number(2200) + "��ʯ\n" +
        HIC"ʣ��������"HIW+chinese_number(7 - me->query("jijin/lingqu3")) + "��\n" +
        NOR);		
	}else	{tell_object(me,ZJSIZE(26)+HIR"����δ����߼�����\n"+NOR);
		}
    if(me->query("jijin/ss4")==1)
	{
       tell_object(me,HIG"�㵱ǰ������ؼ�����ʣ��������£�\n" +
		HIC"ÿ����ȡ��"HIW+chinese_number(4300) + "��ʯ\n" +
        HIC"ʣ��������"HIW+chinese_number(7 - me->query("jijin/lingqu4")) + "��\n" +
        NOR);		
	}else	{tell_object(me,ZJSIZE(26)+HIR"����δ�����ؼ�����\n"+NOR);
		}		
	return 1;
}
int do_choose(string arg)//������
{
	int shimen,flag,dj;
	string str;
    string a;
	object ob1,ob2;
	object me = this_player();
	shimen = me->query("shimen/today");
dj=me->query("zjvip/all_pay")/10;

        if (! arg) 

        return notify_fail(INPUTTXT(ZJSIZE(25)HIW BBLK"���ֶ�������Ҫ����Ļ���,����"NOR+ZJBR+ZJSIZE(25)+HIY"�����������  ||  �����м�����"NOR+ZJBR+ZJSIZE(25)+HIY"����߼�����  ||  �����ؼ�����"NOR,"choose $txt#")+"\n");
		if(me->is_fighting())
	{tell_object(me,"��������ս����\n");
		return 1;}
		if(me->is_busy())
	{tell_object(me,"����æ��\n");
		return 1;}
//	sscanf(arg,"%d",flag);
	switch (arg) {
	  case "�����������" :
	  if(me->query("yuanbao")<100000000)
	  {
				tell_object(me,"һ�ܽ�����һ�칺��\n");
				return 1;
	  }
			if(me->query("yuanbao") >= 2000 && me->query("jijin/ss1") != 1)
			{
				me->add("yuanbao",-2000);
				me->set("jijin/ss1",1);
				tell_object(me,"����ɹ�������7�죬ÿ�����������ȡ450��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"�����ʯ��������Ѿ�������ˡ�"NOR"\n", me);
	    return 0;}
		break;
	  case "�����м�����" :
	  if(me->query("yuanbao")<100000000)
	  {
				tell_object(me,"һ�ܽ�����һ�칺��\n");
				return 1;
	  }
			if(me->query("vipdj") < 2)
			{
				tell_object(me,"�����м�������Ҫvip�ȼ��ﵽ2����\n");
				return 1;
			}
			if(me->query("yuanbao") >= 5000 && me->query("jijin/ss2") != 1)
			{
				me->add("yuanbao",-5000);
				me->set("jijin/ss2",1);
				tell_object(me,"����ɹ�������7�죬ÿ�����������ȡ1000��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"�����ʯ��������Ѿ�������ˡ�"NOR"\n", me);
	    return 0;}
		break;
	  case "����߼�����" :
	  if(me->query("yuanbao")<100000000)
	  {
				tell_object(me,"һ�ܽ�����һ�칺��\n");
				return 1;
	  }
			if(me->query("vipdj") < 4)
			{
				tell_object(me,"����߼�������Ҫvip�ȼ��ﵽ4����\n");
				return 1;
			}
			if(me->query("yuanbao") >= 10000 && me->query("jijin/ss3") != 1)
			{
				me->add("yuanbao",-10000);
				me->set("jijin/ss3",1);
				tell_object(me,"����ɹ�������7�죬ÿ�����������ȡ2200��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"�����ʯ��������Ѿ�������ˡ�"NOR"\n", me);
	    return 0;}
		break;
	  case "�����ؼ�����" :
	  if(me->query("yuanbao")<100000000)
	  {
				tell_object(me,"һ�ܽ�����һ�칺��\n");
				return 1;
	  }
			if(me->query("vipdj") < 6)
			{
				tell_object(me,"�����ؼ�������Ҫvip�ȼ��ﵽ6����\n");
				return 1;
			}
			if(me->query("yuanbao") >= 20000 && me->query("jijin/ss4") != 1)
			{
				me->add("yuanbao",-20000);
				me->set("jijin/ss4",1);
				tell_object(me,"����ɹ�������7�죬ÿ�����������ȡ4300��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"�����ʯ��������Ѿ�������ˡ�"NOR"\n", me);
	    return 0;}
		break;
	  default :
		message_vision(HIC "��������ȷ�Ļ������ƣ����磺�����������\n" NOR,me);
		return notify_fail("��������ȷ�Ļ������ƣ����磺�����������\n");
	}		

			
//	tell_object(me,"��δ����ȡʱ�䣡\n");
	return 1;
}
int do_choose1(int arg)//����������ȡ
{
	object ob, me,env ,bing , obj1,obj2,obj3,obj4;
	mixed *localtime, *localtime2;
	string writeFile, ip, ip2, *meFilePach, meFile, item_max, id, room, target;
	int i, fen, j, ok, day, month, size, data,flag;
        int level;
			ob = this_object();
        	me = this_player();

    if(me->query("jijin/ss1")!=1)
	{
		tell_object(me,CYN"����δ����û���\n"NOR);
		return 1;
	}
    if(me->query("jijin/lingqu1")>=7)
	{
		tell_object(me,CYN"�û������Ѿ�7��ȫ�������ˡ�\n"NOR);
		return 1;
	}
	if (ob->query_temp("qiandao_time") >time())
	{
		tell_object(me,CYN"����ү˵������һ��������\n"NOR);
		return 1;
	}
	data = me->query("jijinss1/time");
	localtime = localtime(data);
	localtime2 = localtime(time());

	if(data && localtime[LT_MDAY]  == localtime2[LT_MDAY])
	{
		tell_object(me, CYN"����ү˵����������Ѿ�����������ˣ����������ɡ�\n"NOR);
		return 1;
	}
	if(localtime[LT_MON] + 1 != localtime2[LT_MON] + 1)//�·�
	{
		me->delete("jijinss1");
	}
	ob->set_temp("jijinss1_time", time() + 2);//��÷�ʽ��ȡ��дӲ�̣�����������
	if(writeFile)
	{
		meFile = read_file(writeFile);
		if(meFile)
			meFilePach = explode(meFile,"\n");
		size = sizeof(meFilePach);
		ip = query_ip_number(me);
		item_max = sprintf("ID:%s$Ip:%s$Day:%d$Month:%d", me->query("id"), ip, localtime2[LT_MON] + 1, localtime2[LT_MDAY]);
		for(i=0; i<size; i++)
		{
			sscanf(meFilePach[i], "ID:%s$Ip:%s$Day:%d$Month:%d", id, ip2, day, month);
			if (ip == ip2 && localtime2[LT_MON] + 1 == day && localtime2[LT_MDAY] == month)//��ͬ�ļ����ݱ�ʾ��IP�Ѿ�����ǩ��
			{
				ok =1;
				break;
			} else if (ip == ip2) {//ֻ��IP��ͬ����û��ǩ��
				ok =2;
				meFilePach[i] = "";
				break;
			} else
				ok =0;
		}
	}
	if (ok == 1)
	{
		tell_object(me, CYN"����ү�����IP�����Ѿ�������������ˡ�\n"NOR);
		return 1;
	}
	if (ok == 2)
	{
		write_file(writeFile, "", 1);//��ʼ�����ļ�
		//��д�ļ�
		for(i=0; i<size; i++)
		{
			if(meFilePach[i] == "") continue;//ȥ��IP��ͬ������
			write_file(writeFile, sprintf("%s\n", meFilePach[i]));//��д��������
		}
	}

	message("channel:chat", HIR BBLK"������ү����"+ me->query("name")+"��ȡ�˳�������ÿ��450��ʯ������\n"NOR,users());
	me->add("yuanbao",450);
	me->add("jijinss1/cishu", 1);
	me->add("jijin/lingqu1",1);
	me->set("jijinss1/time", time());
        tell_object(me,HIW"��ȡ�ɹ��������ˣ�\n" +
        450 + "��ʯ\n" +
        NOR);
	return 1;

}
int do_choose2(int arg)//�м�������ȡ
{
	object ob, me,env ,bing , obj1,obj2,obj3,obj4;
	mixed *localtime, *localtime2;
	string writeFile, ip, ip2, *meFilePach, meFile, item_max, id, room, target;
	int i, fen, j, ok, day, month, size, data,flag;
        int level;
			ob = this_object();
        	me = this_player();
    if(me->query("jijin/ss2")!=1)
	{
		tell_object(me,CYN"����δ����û���\n"NOR);
		return 1;
	}
    if(me->query("jijin/lingqu2")>=7)
	{
		tell_object(me,CYN"�û������Ѿ�7��ȫ�������ˡ�\n"NOR);
		return 1;
	}
	if (ob->query_temp("qiandao_time") >time())
	{
		tell_object(me,CYN"����ү˵������һ��������\n"NOR);
		return 1;
	}
	data = me->query("jijinss2/time");
	localtime = localtime(data);
	localtime2 = localtime(time());

	if(data && localtime[LT_MDAY]  == localtime2[LT_MDAY])
	{
		tell_object(me, CYN"����ү˵����������Ѿ�����������ˣ����������ɡ�\n"NOR);
		return 1;
	}
	if(localtime[LT_MON] + 1 != localtime2[LT_MON] + 1)//�·�
	{
		me->delete("jijinss2");
	}
	ob->set_temp("jijinss2_time", time() + 2);//��÷�ʽ��ȡ��дӲ�̣�����������
	if(writeFile)
	{
		meFile = read_file(writeFile);
		if(meFile)
			meFilePach = explode(meFile,"\n");
		size = sizeof(meFilePach);
		ip = query_ip_number(me);
		item_max = sprintf("ID:%s$Ip:%s$Day:%d$Month:%d", me->query("id"), ip, localtime2[LT_MON] + 1, localtime2[LT_MDAY]);
		for(i=0; i<size; i++)
		{
			sscanf(meFilePach[i], "ID:%s$Ip:%s$Day:%d$Month:%d", id, ip2, day, month);
			if (ip == ip2 && localtime2[LT_MON] + 1 == day && localtime2[LT_MDAY] == month)//��ͬ�ļ����ݱ�ʾ��IP�Ѿ�����ǩ��
			{
				ok =1;
				break;
			} else if (ip == ip2) {//ֻ��IP��ͬ����û��ǩ��
				ok =2;
				meFilePach[i] = "";
				break;
			} else
				ok =0;
		}
	}
	if (ok == 1)
	{
		tell_object(me, CYN"����ү�����IP�����Ѿ�������������ˡ�\n"NOR);
		return 1;
	}
	if (ok == 2)
	{
		write_file(writeFile, "", 1);//��ʼ�����ļ�
		//��д�ļ�
		for(i=0; i<size; i++)
		{
			if(meFilePach[i] == "") continue;//ȥ��IP��ͬ������
			write_file(writeFile, sprintf("%s\n", meFilePach[i]));//��д��������
		}
	}

	message("channel:chat", HIR BBLK"������ү����"+ me->query("name")+"��ȡ���м�����ÿ��1000��ʯ������\n"NOR,users());
	me->add("yuanbao",1000);
	me->add("jijinss2/cishu", 1);
	me->add("jijin/lingqu2",1);

	me->set("jijinss2/time", time());
        tell_object(me,HIW"��ȡ�ɹ��������ˣ�\n" +
        1000 + "��ʯ\n" +
        NOR);
	return 1;

}
int do_choose3(int arg)//�߼�������ȡ
{
	object ob, me,env ,bing , obj1,obj2,obj3,obj4;
	mixed *localtime, *localtime2;
	string writeFile, ip, ip2, *meFilePach, meFile, item_max, id, room, target;
	int i, fen, j, ok, day, month, size, data,flag;
        int level;
			ob = this_object();
        	me = this_player();
    if(me->query("jijin/ss3")!=1)
	{
		tell_object(me,CYN"����δ����û���\n"NOR);
		return 1;
	}
    if(me->query("jijin/lingqu3")>=7)
	{
		tell_object(me,CYN"�û������Ѿ�7��ȫ�������ˡ�\n"NOR);
		return 1;
	}
	if (ob->query_temp("qiandao_time") >time())
	{
		tell_object(me,CYN"����ү˵������һ��������\n"NOR);
		return 1;
	}
	data = me->query("jijinss3/time");
	localtime = localtime(data);
	localtime2 = localtime(time());

	if(data && localtime[LT_MDAY]  == localtime2[LT_MDAY])
	{
		tell_object(me, CYN"����ү˵����������Ѿ�����������ˣ����������ɡ�\n"NOR);
		return 1;
	}
	if(localtime[LT_MON] + 1 != localtime2[LT_MON] + 1)//�·�
	{
		me->delete("jijinss3");
	}
	ob->set_temp("jijinss3_time", time() + 2);//��÷�ʽ��ȡ��дӲ�̣�����������
	if(writeFile)
	{
		meFile = read_file(writeFile);
		if(meFile)
			meFilePach = explode(meFile,"\n");
		size = sizeof(meFilePach);
		ip = query_ip_number(me);
		item_max = sprintf("ID:%s$Ip:%s$Day:%d$Month:%d", me->query("id"), ip, localtime2[LT_MON] + 1, localtime2[LT_MDAY]);
		for(i=0; i<size; i++)
		{
			sscanf(meFilePach[i], "ID:%s$Ip:%s$Day:%d$Month:%d", id, ip2, day, month);
			if (ip == ip2 && localtime2[LT_MON] + 1 == day && localtime2[LT_MDAY] == month)//��ͬ�ļ����ݱ�ʾ��IP�Ѿ�����ǩ��
			{
				ok =1;
				break;
			} else if (ip == ip2) {//ֻ��IP��ͬ����û��ǩ��
				ok =2;
				meFilePach[i] = "";
				break;
			} else
				ok =0;
		}
	}
	if (ok == 1)
	{
		tell_object(me, CYN"����ү�����IP�����Ѿ�������������ˡ�\n"NOR);
		return 1;
	}
	if (ok == 2)
	{
		write_file(writeFile, "", 1);//��ʼ�����ļ�
		//��д�ļ�
		for(i=0; i<size; i++)
		{
			if(meFilePach[i] == "") continue;//ȥ��IP��ͬ������
			write_file(writeFile, sprintf("%s\n", meFilePach[i]));//��д��������
		}
	}

	message("channel:chat", HIR BBLK"������ү����"+ me->query("name")+"��ȡ�˸߼�����ÿ��2200��ʯ������\n"NOR,users());
	me->add("yuanbao",2200);
	me->add("jijinss3/cishu", 1);
	me->add("jijin/lingqu3",1);

	me->set("jijinss3/time", time());
        tell_object(me,HIW"��ȡ�ɹ��������ˣ�\n" +
        2200 + "��ʯ\n" +
        NOR);
	return 1;

}
int do_choose4(int arg)//�ؼ�������ȡ
{
	object ob, me,env ,bing , obj1,obj2,obj3,obj4;
	mixed *localtime, *localtime2;
	string writeFile, ip, ip2, *meFilePach, meFile, item_max, id, room, target;
	int i, fen, j, ok, day, month, size, data,flag;
        int level;
			ob = this_object();
        	me = this_player();
    if(me->query("jijin/ss4")!=1)
	{
		tell_object(me,CYN"����δ����û���\n"NOR);
		return 1;
	}
    if(me->query("jijin/lingqu4")>=7)
	{
		tell_object(me,CYN"�û������Ѿ�7��ȫ�������ˡ�\n"NOR);
		return 1;
	}
	if (ob->query_temp("qiandao_time") >time())
	{
		tell_object(me,CYN"����ү˵������һ��������\n"NOR);
		return 1;
	}
	data = me->query("jijinss4/time");
	localtime = localtime(data);
	localtime2 = localtime(time());

	if(data && localtime[LT_MDAY]  == localtime2[LT_MDAY])
	{
		tell_object(me, CYN"����ү˵����������Ѿ�����������ˣ����������ɡ�\n"NOR);
		return 1;
	}
	if(localtime[LT_MON] + 1 != localtime2[LT_MON] + 1)//�·�
	{
		me->delete("jijinss4");
	}
	ob->set_temp("jijinss4_time", time() + 2);//��÷�ʽ��ȡ��дӲ�̣�����������
	if(writeFile)
	{
		meFile = read_file(writeFile);
		if(meFile)
			meFilePach = explode(meFile,"\n");
		size = sizeof(meFilePach);
		ip = query_ip_number(me);
		item_max = sprintf("ID:%s$Ip:%s$Day:%d$Month:%d", me->query("id"), ip, localtime2[LT_MON] + 1, localtime2[LT_MDAY]);
		for(i=0; i<size; i++)
		{
			sscanf(meFilePach[i], "ID:%s$Ip:%s$Day:%d$Month:%d", id, ip2, day, month);
			if (ip == ip2 && localtime2[LT_MON] + 1 == day && localtime2[LT_MDAY] == month)//��ͬ�ļ����ݱ�ʾ��IP�Ѿ�����ǩ��
			{
				ok =1;
				break;
			} else if (ip == ip2) {//ֻ��IP��ͬ����û��ǩ��
				ok =2;
				meFilePach[i] = "";
				break;
			} else
				ok =0;
		}
	}
	if (ok == 1)
	{
		tell_object(me, CYN"����ү�����IP�����Ѿ�������������ˡ�\n"NOR);
		return 1;
	}
	if (ok == 2)
	{
		write_file(writeFile, "", 1);//��ʼ�����ļ�
		//��д�ļ�
		for(i=0; i<size; i++)
		{
			if(meFilePach[i] == "") continue;//ȥ��IP��ͬ������
			write_file(writeFile, sprintf("%s\n", meFilePach[i]));//��д��������
		}
	}

	message("channel:chat", HIR BBLK"������ү����"+ me->query("name")+"��ȡ���ؼ�����ÿ��4300��ʯ������\n"NOR,users());
	me->add("yuanbao",4300);
	me->add("jijinss4/cishu", 1);
	me->add("jijin/lingqu4",1);
	me->set("jijinss4/time", time());
        tell_object(me,HIW"��ȡ�ɹ��������ˣ�\n" +
        4300 + "��ʯ\n" +
        NOR);
	return 1;

}

