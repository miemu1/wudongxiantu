// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC"�޶��׹���װ"NOR,({"baigu"}));
	set_weight(1);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"�򿪿ɻ��2121�׹�ϵ����װ��\n"ZJURL("cmds:openbox baigu")ZJSIZE(15)"�򿪿���"NOR"\n");
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
    add_action("do_openbox","openbox baigu",1);
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


	ob = new("clone/good/baigu/bg1");
	ob->move(me);
	ob = new("clone/good/baigu/bg2");
	ob->move(me);
	ob = new("clone/good/baigu/bg3");
	ob->move(me);
	ob = new("clone/good/baigu/bg4");
	ob->move(me);
	ob = new("clone/good/baigu/bg5");
	ob->move(me);
	ob = new("clone/good/baigu/bg6");
	ob->move(me);
	ob = new("clone/good/baigu/bg7");
	ob->move(me);
	ob = new("clone/good/baigu/bg8");
	ob->move(me);
	ob = new("clone/good/baigu/bg9");
	ob->move(me);
	ob = new("clone/good/baigu/bg10");
	ob->move(me);
	ob = new("clone/good/baigu/bg11");
	ob->move(me);
	ob = new("clone/good/baigu/bg12");
	ob->move(me);

        tell_object(me,HIW"�����ˣ�\n" +
        1 + "���׹Ǽ�\n" +
        1 + "���׹ǽ�\n" +
        1 + "���׹���\n" +
        1 + "���׹ǿ�\n" +
        1 + "���׹���\n" +
        1 + "���׹���\n" +
        1 + "���׹�ѥ\n" +
        1 + "���׹���\n" +
        1 + "���׹���\n" +
        1 + "���׹Ƕ�\n" +
        1 + "���׹���\n" +
        1 + "���׹���\n" +
		
        NOR);

    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}