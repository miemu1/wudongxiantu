// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC"�޶�׷����װ"NOR,({"zhuiyue"}));
	set_weight(1);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"�򿪿ɻ��2121׷��ϵ����װ��\n"ZJURL("cmds:openbox zhuiyue")ZJSIZE(15)"�򿪿���"NOR"\n");
	    set("unit","��");
	    set("win_box",1);
		set("credit",300);
		set("no_drop", 1);
		set("no_put", 1);

	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox zhuiyue",1);
}
//�򿪱���ĺ���
int do_openbox()
{
   int i;
   int num=1;
   string obj="";
   object ob;


	object me = this_player();
	if (me->is_busy())
	{ write("����һ������δ��ɣ�\n"); return 1;}
	if( me->is_fighting() )
	{ write("�ȸ����ⳡ���ٴ򿪡�\n"); return 1;}


	ob = new("clone/good/zhuiyue/bg1");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg2");
	ob->move(me);
//	ob = new("clone/good/zhuiyue/bg3");
//	ob->move(me);
	ob = new("clone/good/zhuiyue/bg4");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg5");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg6");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg7");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg8");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg9");
	ob->move(me);
//	ob = new("clone/good/zhuiyue/bg10");
//	ob->move(me);
	ob = new("clone/good/zhuiyue/bg11");
	ob->move(me);
	ob = new("clone/good/zhuiyue/bg12");
	ob->move(me);

        tell_object(me,HIW"�����ˣ�\n" +
        1 + "�����п� �� ׷�¼�\n" +
        1 + "�����п� �� ׷�½�\n" +
        1 + "�����п� �� ׷����\n" +
        1 + "�����п� �� ׷�¿�\n" +
        1 + "�����п� �� ׷����\n" +
        1 + "�����п� �� ׷����\n" +
        1 + "�����п� �� ׷��ѥ\n" +
 //       1 + "���׹���\n" +
//        1 + "���׹���\n" +
        1 + "�����п� �� ׷�¶�\n" +
        1 + "�����п� �� ׷����\n" +
        1 + "�����п� �� ׷����\n" +
		
        NOR);

    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}