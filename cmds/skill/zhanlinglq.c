// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
#define REDBAO "/u/aliyun/obj/bao"
void create()
{
seteuid(getuid());
}
int main(object me, string arg)
{
	    object obj,ob,obj1,obj2,obj3,obj4;
        int count,mengxin;
        string a;
		me = this_player();
		a = "��������";
        if (! arg) 

        return notify_fail(INPUTTXT(ZJSIZE(18)MAG BBLK"��"NOR,"zhanling $txt#")+"\n");
		if(me->is_fighting())
	{
		tell_object(me,"��������ս����\n");
		return 1;
	}
		if(me->is_busy())
	{
		tell_object(me,"����æ��\n");
		return 1;
	}
	switch (arg) {
	  case "1" :
			if(me->query("zhanling/dj") >= 1 && me->query("zhanlinglq/s1") != 1)
			{
			me->add("jifeng",1000);
				me->set("zhanlinglq/s1",1);
				tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "2" :
			if(me->query("zhanling/dj") >= 2 && me->query("zhanlinglq/s2") != 1)
			{
			me->add("jifeng",1000);
				me->set("zhanlinglq/s2",1);
				tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "3" :
			if(me->query("zhanling/dj") >= 3 && me->query("zhanlinglq/s3") != 1)
			{
			me->add("jifeng",1000);

				me->set("zhanlinglq/s3",1);
				tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "4" :
			if(me->query("zhanling/dj") >= 4 && me->query("zhanlinglq/s4") != 1)
			{
			me->add("jifeng",1000);
				me->set("zhanlinglq/s4",1);
				tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "5" :
			if(me->query("zhanling/dj") >= 5 && me->query("zhanlinglq/s5") != 1)
			{
			me->add("jifeng",1000);
				me->set("zhanlinglq/s5",1);
				tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "6" :
			if(me->query("zhanling/dj") >= 6 && me->query("zhanlinglq/s6") != 1)
			{
			me->add("jifeng",1000);
			me->set("zhanlinglq/s6",1);
			tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "7" :
			if(me->query("zhanling/dj") >= 7 && me->query("zhanlinglq/s7") != 1)
			{
			me->add("jifeng",1000);
			me->set("zhanlinglq/s7",1);
			tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "8" :
			if(me->query("zhanling/dj") >= 8 && me->query("zhanlinglq/s8") != 1)
			{
			me->add("jifeng",1000);
			me->set("zhanlinglq/s8",1);
			tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "9" :
			if(me->query("zhanling/dj") >= 9 && me->query("zhanlinglq/s9") != 1)
			{
			me->add("jifeng",1000);
			me->set("zhanlinglq/s9",1);
			tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "10" :
			if(me->query("zhanling/dj") >= 10 && me->query("zhanlinglq/s10") != 1)
			{
			me->add("jifeng",1000);
			me->set("zhanlinglq/s10",1);
			tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "11" :
			if(me->query("zhanling/dj") >= 11 && me->query("zhanlinglq/s11") != 1)
			{
			me->add("jifeng",1000);
			me->set("zhanlinglq/s11",1);
			tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "12" :
			if(me->query("zhanling/dj") >= 12 && me->query("zhanlinglq/s12") != 1)
			{
			me->add("jifeng",1000);
			me->set("zhanlinglq/s12",1);
			tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "13" :
			if(me->query("zhanling/dj") >= 13 && me->query("zhanlinglq/s13") != 1)
			{
			me->add("jifeng",1000);
			me->set("zhanlinglq/s13",1);
			tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "14" :
			if(me->query("zhanling/dj") >= 14 && me->query("zhanlinglq/s14") != 1)
			{
			me->add("jifeng",1000);
			me->set("zhanlinglq/s14",1);
			tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "15" :
			if(me->query("zhanling/dj") >= 15 && me->query("zhanlinglq/s15") != 1)
			{
			me->add("jifeng",1000);
			me->set("zhanlinglq/s15",1);
			tell_object(me,"��ȡ�ɹ���������1000�ŵ�ȯ��\n��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "16" :
			if(me->query("zhanling/dj") >= 16 && me->query("zhanlinglq/s16") != 1)
			{
			me->add("yuanbao",500);
			me->set("zhanlinglq/s16",1);
			tell_object(me,"��ȡ�ɹ���������500��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "17" :
			if(me->query("zhanling/dj") >= 17 && me->query("zhanlinglq/s17") != 1)
			{
			me->add("yuanbao",500);
			me->set("zhanlinglq/s17",1);
			tell_object(me,"��ȡ�ɹ���������500��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "18" :
			if(me->query("zhanling/dj") >= 18 && me->query("zhanlinglq/s18") != 1)
			{
			me->add("yuanbao",500);
			me->set("zhanlinglq/s18",1);
			tell_object(me,"��ȡ�ɹ���������500��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "19" :
			if(me->query("zhanling/dj") >= 19 && me->query("zhanlinglq/s19") != 1)
			{
			me->add("yuanbao",500);
			tell_object(me,"��ȡ�ɹ���������500��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "20" :
			if(me->query("zhanling/dj") >= 20 && me->query("zhanlinglq/s20") != 1)
			{
			me->add("yuanbao",500);
			me->set("zhanlinglq/s20",1);
			tell_object(me,"��ȡ�ɹ���������500ö��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "21" :
			if(me->query("zhanling/dj") >= 21 && me->query("zhanlinglq/s21") != 1)
			{
			me->add("yuanbao",500);
			tell_object(me,"��ȡ�ɹ���������500��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "22" :
			if(me->query("zhanling/dj") >= 22 && me->query("zhanlinglq/s22") != 1)
			{
			me->add("yuanbao",500);
			me->set("zhanlinglq/s22",1);
			tell_object(me,"��ȡ�ɹ���������500ö��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "23" :
			if(me->query("zhanling/dj") >= 23 && me->query("zhanlinglq/s23") != 1)
			{
			me->add("yuanbao",500);
			me->set("zhanlinglq/s23",1);
			tell_object(me,"��ȡ�ɹ���������500ö��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "24" :
			if(me->query("zhanling/dj") >= 24 && me->query("zhanlinglq/s24") != 1)
			{
			me->add("yuanbao",500);
			me->set("zhanlinglq/s24",1);
			tell_object(me,"��ȡ�ɹ���������500ö��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "25" :
			if(me->query("zhanling/dj") >= 25 && me->query("zhanlinglq/s25") != 1)
			{
			me->add("yuanbao",500);
			me->set("zhanlinglq/s25",1);
			tell_object(me,"��ȡ�ɹ���������500ö��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "26" :
			if(me->query("zhanling/dj") >= 26 && me->query("zhanlinglq/s26") != 1)
			{
			me->add("yuanbao",500);
			me->set("zhanlinglq/s26",1);
			tell_object(me,"��ȡ�ɹ���������500ö��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "27" :
			if(me->query("zhanling/dj") >= 27 && me->query("zhanlinglq/s27") != 1)
			{
			me->add("yuanbao",500);
			me->set("zhanlinglq/s27",1);
			tell_object(me,"��ȡ�ɹ���������500ö��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "28" :
			if(me->query("zhanling/dj") >= 28 && me->query("zhanlinglq/s28") != 1)
			{
			me->add("yuanbao",1500);
			me->set("zhanlinglq/s28",1);
			tell_object(me,"��ȡ�ɹ���������1500��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "29" :
			if(me->query("zhanling/dj") >= 29 && me->query("zhanlinglq/s29") != 1)
			{
			me->add("yuanbao",3500);
			me->set("zhanlinglq/s29",1);
			tell_object(me,"��ȡ�ɹ���������3500��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  case "30" :
			if(me->query("zhanling/dj") >= 30 && me->query("zhanlinglq/s30") != 1)
			{
			me->add("yuanbao",5000);
			me->set("zhanlinglq/s30",1);
			tell_object(me,"��ȡ�ɹ���������5000��ʯ��\n");
				return 1;
			}else
	{message_vision(HIG"���ս��ȼ���������Ѿ���ȡ��һ���ˡ�"NOR"\n", me);
	    return 1;}
		break;
	  default :
		message_vision(HIC "��ȡ��������ϵ��ʦ��\n" NOR,me);
	}		
              sscanf(arg, "%s ", a);


        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��giveall ��Ʒ·��

�����ߵ�������Һ����
HELP
        );
        return 1;
}
