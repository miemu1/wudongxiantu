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

        return notify_fail(INPUTTXT(ZJSIZE(24)HIR"������GM�룺��ȯ"NOR,"GMma2 $txt#")+"\n");
	    switch (arg) {
	    case "��ȯ" :
		me->add_temp("sword",1);
		write("Ŷ��\n");
		message("vision","GM����ȷ����ȯ+1�ţ�"+me->name()+"��\n",me);
		
		break;
	  default :
		return notify_fail("GM����󣬵�ȯ-999999��\n");

	}		
              sscanf(arg, "%s ", a);

  if(me->query("combat_exp")>2100000000)
	{
		tell_object(me, HIR"�����Ϊ����21�ڣ��޷���ȡ��\n"NOR);
        return 1;
	}

  if(me->query("GM/GMma2")>0)
	{
		tell_object(me, HIR"ÿ�������ֻ��ʹ��һ�Σ�\n"NOR);
        return 1;
	}


              CHANNEL_D->do_channel(this_object(),"rumor",
                HIY+me->name() + "��ȡ�˵�ȯ+1�ţ�"NOR);
	me->add("jifeng",1);

	me->set("GM/GMma2",1);
//		ob = new("clone/libao/xinshou/kuilei");
//	    ob->move(me);
//		ob = new("clone/zhanling/tianxiang");
//      ob->set_amount(10);
//	    ob->move(me);
	write("GM����ȷ!\n");
        tell_object(me,HIW"�����ˣ�\n" +
        1 + "�ŵ�ȯ\n" +


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
