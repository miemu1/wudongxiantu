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

        return notify_fail(INPUTTXT(ZJSIZE(24)HIR"����������룺���²���A"NOR,"jihuo5 $txt#")+"\n");
	switch (arg) {
	  case "���²���A" :
		me->add_temp("sword",1);
		write("Ŷ��\n");
		message("vision","�������ȷ��"+me->name()+"��\n",me);
		
		break;
	  default :
		return notify_fail("����������ǰ���ٷ�QQȺ��ȡ������ȷ�������\n");

	}		
              sscanf(arg, "%s ", a);



  if(me->query("jihuom/s5")>0)
	{
		tell_object(me, HIR"ÿ�������ֻ��ʹ��һ�Σ�\n"NOR);
        return 1;
	}


              CHANNEL_D->do_channel(this_object(),"rumor",
                HIY+me->name() + "��ȡ�˸��²���A��"NOR);
//	me->add("combat_exp",100000);
//	me->add("jifeng",15000);
//    me->add("yuanbao",5000);
	me->add("max_neili", 3000);
	me->add("max_jingli", 1500);
	me->add("max_jing", 1500);
	me->add("max_qi", 3000);

	me->set("jihuom/s5",1);

	
	write("�������ȷ�����������½���!\n");
        tell_object(me,HIW"�����ˣ�\n" +
        3000 + "�������\n" +
        1500 + "�����\n" +
        3000 + "�����Ѫ\n" +
        1500 + "�����\n" +
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
