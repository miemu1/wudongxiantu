#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "戾气" NOR, ({ "liqi wan", "wan"}) );
	set_weight(200);
      set("suit_point", 100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗据说吃了可以减少戾气的丹药。\n");
                set("value", 10000);
		set("unit", "颗");
		set("only_do_effect", 1);
	}
}

int do_effect(object me)
{
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
        if (me->query("total_hatred") < 0)
        {
                message_vision("$N眨眨眼。\n", me);
                tell_object(me, "你觉得这药没啥味道，还不如花生好吃。\n");
        return 0;
        } 
        if (me->query("total_hatred") > 49)
        {
                me->add("total_hatred", -50);
                 write("\n "+HIR+"恭喜你："+NOR+HIG+"戾气减少50点！！！ "+NOR);
        }else
        {
                tell_object(me, "不过你觉得好像没什么作用。\n");
        }
        destruct(this_object());
	return 1;
}
