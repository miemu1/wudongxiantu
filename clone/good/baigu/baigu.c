// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC"限定白骨套装"NOR,({"baigu"}));
	set_weight(1);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"打开可获得2121白骨系列套装！\n"ZJURL("cmds:openbox baigu")ZJSIZE(15)"打开看看"NOR"\n");
	    set("unit","个");
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
//打开宝箱的函数
int do_openbox()
{
   int i;
   int num=1;
   string obj="";
   object ob;


	object me = this_player();
	if (me->is_busy())
	{ write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	{ write("先干完这场架再打开。\n"); return 1;}


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

        tell_object(me,HIW"你获得了：\n" +
        1 + "件白骨甲\n" +
        1 + "件白骨戒\n" +
        1 + "件白骨手\n" +
        1 + "件白骨盔\n" +
        1 + "件白骨链\n" +
        1 + "件白骨腿\n" +
        1 + "件白骨靴\n" +
        1 + "件白骨衣\n" +
        1 + "件白骨披\n" +
        1 + "件白骨盾\n" +
        1 + "件白骨腰\n" +
        1 + "件白骨腕\n" +
		
        NOR);

    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}