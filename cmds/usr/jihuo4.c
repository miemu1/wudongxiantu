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
	    object obj,ob;
        int count,mengxin;
        string a;
		me = this_player();
        if (! arg) 

        return notify_fail(INPUTTXT(ZJSIZE(24)HIR "����������룺�Ұ����"NOR,"jihuo4 $txt#")+"\n");
	switch (arg) {
	  case "�Ұ����" :
		me->add_temp("sword",1);
		write("Ŷ��\n");
		message("vision","�������ȷ��"+me->name()+"��\n",me);
		
		break;
	  default :
		return notify_fail("����������ǰ���ٷ�QQȺ��ȡ������ȷ�������\n");

	}		
              sscanf(arg, "%s ", a);



  if(me->query("jihuom/s4")>0)
	{
		tell_object(me, HIR"ÿ�������ֻ��ʹ��һ�Σ�\n"NOR);
        return 1;
	}


              CHANNEL_D->do_channel(this_object(),"rumor",
                HIY+me->name() + "��ʾ�Һܰ�����"NOR);
//	me->add("combat_exp",100000);
	me->add("potential",5000000);
//	me->add("max_neili", 500);
//	me->add("max_jingli", 500);

	me->set("jihuom/s4",1);
//	ob = new("clone/zhongqiu/50jing");
//	ob->move(me);
//	ob = new("clone/zhongqiu/jiuzhuan");
//  ob->set_amount(5);
//	ob->move(me);
//	ob = new("clone/zhongqiu/wannian");
//	ob->move(me);
	ob = new("clone/zhongqiu/shimen1000");
	ob->move(me);
//	ob = new("clone/zhongqiu/shimen1000");
//	ob->move(me);
	write("�������ȷ�����������½���!\n");
        tell_object(me,HIW"�����ˣ�\n" +
//        1 + "��+50����ʯ\n" +
		1 + "��ʦ��1000������\n" +
//        5 + "�ž�ת�𵤡�\n"+
//       1 + "��������֥��\n"+
        500 + "��Ǳ�ܡ�\n"+

        NOR);
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
