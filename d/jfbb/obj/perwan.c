// shenliwan.c 美容丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "美容丸" NOR, ({ "meili wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗七彩的美容丸，据说吃了可以变美。无限制使用\n");
		set("no_put",1);
              	set("no_sell",1);
              	set("no_drop",1); 
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        me = this_player();
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);

                tell_object(me, HIR "你觉得似乎自己变美了一些。\n" NOR);
                me->add("per", 1);
        destruct(this_object());
	return 1;
}
