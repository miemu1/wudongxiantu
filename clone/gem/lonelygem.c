// 独孤九剑宝石

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIM "剑道石" NOR, ({ "lonely gem" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIM "一块内涵剑道的石头。"NOR"\n");
		set("base_value", 20000);
		set("base_weight", 1);
		set("base_unit", "片");
		set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_teal", 1);
		set("can_be_enchased", 1);
		set("magic/type", "all");
		set("magic/power", 200);
		set("can_be_inlay",([
		"name":"剑道石",
		"skill":"lonely-sword",
		])
		);
	}
	set_amount(1);
	setup();
}
