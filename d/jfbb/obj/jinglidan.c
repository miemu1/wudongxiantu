// shenliwan.c 美容丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "精力丸" NOR, ({ "jingli shenwan", "shenwan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗精力丸,吃了可增加精力！\n");
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
        if (me->query("max_jinglili") >= 50000000)
        {
                message_vision("$N突然放了一个奇臭无比的响屁。\n", me);
                tell_object(me, "你觉得大概是吃坏了肚子。\n");
        } else
        {
                message("vision", "你似乎听见" + me->name() + "的全身哗啦啦的响。\n",
                                  environment(me), ({ me }));
                tell_object(me, HIY "你感觉精力似乎一下子充实了，整个人神清气爽，"
                                "好在一会儿就停了下来，似乎精力更雄厚了。\n" NOR);
                me->add("max_jingli", 3000);
        }

        destruct(this_object());
	return 1;
}

