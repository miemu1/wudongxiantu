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

        return notify_fail(INPUTTXT(ZJSIZE(24)HIR"����������룺����ʹ��"NOR,"jihuo10 $txt#")+"\n");
	switch (arg) {
	  case "����ʹ��" :
		me->add_temp("sword",1);
		write("Ŷ��\n");
		message("vision","�������ȷ��"+me->name()+"��\n",me);
		
		break;
	  default :
		return notify_fail("����������ǰ���ٷ�QQȺ��ȡ������ȷ�������\n");

	}		
              sscanf(arg, "%s ", a);
  if(me->query("jihuom/s10")>0)
	{
		tell_object(me, HIR"ÿ�������ֻ��ʹ��һ�Σ�\n"NOR);
        return 1;
	}


              CHANNEL_D->do_channel(this_object(),"rumor",
                HIY+me->name() + "��ȡ������ʹ�ߣ�"NOR);
	me->add("potential",5000000);
//	me->add("clone\vip2\qilin.c",5);
//    me->add("dajif",500);
//	me->add("max_neili", 500);
//	me->add("max_jingli", 500);

	me->set("jihuom/s10",1);

//	ob = new("clone/vip2/qilin");
  //  ob->set_amount(3);
//	ob->move(me);

//	ob = new("clone/vip2/xuanling");
 //   ob->set_amount(6);
//	ob->move(me);


//	ob = new("clone/good/qianghua_crystal");
//    ob->set_amount(1);
//	ob->move(me);
	
	ob = new("clone/aaa/vip2/kuilei");
    ob->set_amount(5);
	ob->move(me);
	
	write("�������ȷ�����������½���!\n");
        tell_object(me,HIW"�����ˣ�\n" +
        500 + "��Ǳ��\n" +
//       500 + "��ʯ\n" +
        5 + "�������\n" +
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
