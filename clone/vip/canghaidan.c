// shenliwan.c 神力丸

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC "沧海丹" NOR, ({ "canghai dan", "dan"}) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一小粒沧海丹还不够塞牙缝的,但效果依旧。\n");
		set("spectxt", "一小粒沧海丹还不够塞牙缝的,但效果依旧。\n");
		set("yuanbao", 1);
		set("unit", "粒");
		set("only_do_effect", 1);
	}
}

int do_effect(object me)
{
	mapping my;
      if (me->is_fighting()&&playerp(me->query("competitor"))) 
		return notify_fail("你现在正在和玩家战斗！\n");

	message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +"。\n", me);

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	me->set("qi",me->query("max_qi")+me->query("gain/max_qi"));

	me->set("eff_qi",me->query("max_qi")+me->query("gain/max_qi"));

	my["neili"]  = my["max_neili"];
	my["food"]   = 77*me->max_food_capacity();
	my["water"]  = 77*me->max_water_capacity();
	me->start_busy(2);
	return 1;
}
int query_autoload() { return 1; }