
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG "临时加倍丹" NOR, ({"exp dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一颗能够临时提升你一倍修为潜能的丹药，下线失效。\n");
                set("base_unit", "颗");
                set("base_value", 10000);
                set("no_sell", 1);
                set("base_weight", 80);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        mapping my;

        if (time() - me->query_temp("last_eat/exp") < 3600)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        me->set_temp("last_eat/exp", time());

        tell_object(me, HIG "增加一倍修为潜能。"NOR"\n");

        log_file("static/using", sprintf("%s(%s) eat 加倍丹 at %s.\n",
                        me->name(1), me->query("id"), ctime(time())));

		destruct(this_object());
	return 1;
}
