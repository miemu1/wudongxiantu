// lingzhi.c 千年雪莲
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
 set_name(HIR"万年野菊花"NOR, ({"xu ou", "ou"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
set("long", "这是一棵武林人士梦寐以求的万年野菊花，据说吃一棵可得增长精力内力上限。\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

this_player()->add("max_jingli", 10000);
this_player()->add("max_neili", 10000);
this_player()->add("eff_jingli",10000);
 message_vision("$N吃下一棵万年野菊花，只觉得自己的修为又增长了一些 !\n", this_player());
	destruct(this_object());
	return 1;
}

