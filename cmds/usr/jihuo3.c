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

        return notify_fail(INPUTTXT(ZJSIZE(24)HIR"����������룺���²���C"NOR,"jihuo3 $txt#")+"\n");
	switch (arg) {
	  case "���²���C" :
		me->add_temp("sword",1);
		write("Ŷ��\n");
		message("vision","�������ȷ��"+me->name()+"��\n",me);
		
		break;
	  default :
		return notify_fail("����������ǰ���ٷ�QQȺ��ȡ������ȷ�������\n");

	}		
              sscanf(arg, "%s ", a);



  if(me->query("jihuom/s3")>0)
	{
		tell_object(me, HIR"ÿ�������ֻ��ʹ��һ�Σ�\n"NOR);
        return 1;
	}


              CHANNEL_D->do_channel(this_object(),"rumor",
                HIY+me->name() + "��ȡ�˸��²���B��"NOR);
//	me->add("combat_exp",100000);
//	me->add("clone\vip2\qilin.c",5);
    me->add("yuanbao",500);
//	me->add("max_neili", 500);
//	me->add("max_jingli", 500);

	me->set("jihuom/s3",1);

	ob = new("HELL8/BOX/box1");
    ob->set_amount(1);
	ob->move(me);

	ob = new("HELL8/BOX/box2");
    ob->set_amount(1);
	ob->move(me);

	ob = new("HELL8/BOX/box3");
    ob->set_amount(6);
	ob->move(me);

	ob = new("HELL8/BOX/box4");
    ob->set_amount(6);
	ob->move(me);
	
	write("�������ȷ�����������½���!\n");
        tell_object(me,HIW"�����ˣ�\n" +
        1 + "��������\n" +
        1 + "�׻�����\n" +
        1 + "��ȸ����\n" +
        1 + "���䱦��\n" +
        500 + "��ʯ\n" +
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
