// jinsha.c

#include <ansi.h>
inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIY "星辰砂" NOR, ({ "jin shas" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "用来强化装备的道具。\n");
		set("base_unit", "粒");
		set("base_value", 10);
		set("yuanbao", 1);
		set("item_exp",10000000);
		set("base_weight", 1);
	}
	setup();
}

