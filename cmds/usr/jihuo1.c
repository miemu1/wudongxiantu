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

        return notify_fail(INPUTTXT(ZJSIZE(24)HIR"����������룺�������"NOR,"jihuo1 $txt#")+"\n");
	switch (arg) {
	  case "�������" :
		me->add_temp("sword",1);
		write("Ŷ��\n");
		message("vision","�������ȷ����ӭ�����䶯��;MUD��"+me->name()+"��\n",me);
		
		break;
	  default :
		return notify_fail("����������ǰ���ٷ�QQȺ��ȡ������ȷ�������\n");

	}		
              sscanf(arg, "%s ", a);

  if(me->query("combat_exp")>5000000)
	{
		tell_object(me, HIR"�����Ϊ����500�򣬲����������ˣ�\n"NOR);
        return 1;
	}

  if(me->query("jihuom/s1")>0)
	{
		tell_object(me, HIR"ÿ�������ֻ��ʹ��һ�Σ�\n"NOR);
        return 1;
	}


              CHANNEL_D->do_channel(this_object(),"rumor",
                HIY+me->name() + "���潭������������������룡"NOR);
	me->add("combat_exp",1000000);
	me->add("potential",5000000);
	me->add("max_neili", 1000);
	me->add("max_jingli", 1000);
	me->add("jifeng", 500);

	me->set("jihuom/s1",1);

	ob = new("clone/tianji1/xuemaid");
    ob->set_amount(1);
	ob->move(me);

	ob = new("clone/jifeng/1shimen");
    ob->set_amount(1);
	ob->move(me);

	ob = new("clone/jifeng/1bt");
    ob->set_amount(1);
	ob->move(me);

	ob = new("clone/tianji1/0qnvip");
    ob->set_amount(1);
	ob->move(me);
	write("�������ȷ�����������½���!\n");
        tell_object(me,HIW"�����ˣ�\n" +
        100 + "����Ϊ\n" +
		500 + "��Ǳ��\n" +
		500 + "��ȯ\n" +
        1000+ "�������޺;������ޡ�\n"+
        1 + "�Ű���Ѫ������\n"+
        1 + "������Ǳ���¿���\n"+
        1 + "���Զ�ʦ�š�\n"+
        1 + "��BT����\n"+
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
