#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "聚元丹" NOR, ({ "ju yuan", "dan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗吃了能吸收天地灵气充饥的丹药。\n");
                set("value", 100);
		set("unit", "颗");
		set("only_do_effect", 1);
	}
}

int do_effect(object me)
{
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
        if (me->query("food") > 1000)
        {
                message_vision("$N眨眨眼。\n", me);
                tell_object(me, "你觉得这药没啥味道，还不如花生好吃。\n");
        return 0;
        } 
        if (me->query("water") > 1000)
        {
                tell_object(me, "不过你觉得好像没什么作用。\n");
        return 0;
        }
      me->add("food", 5000);
      me->add("water", 5000);
      write("\n "HIR"你不再感到饥饿与口渴。"NOR);
     destruct(this_object());
	return 1;
}
