// shedan.c

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
	set_name("优质木材", ({"youzhiwood material", "mu cai"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("base_unit", "根");
		set("long", "这是一根砍下的优质的木材。\n");
		set("base_value", 5000);
		set("base_weight", 1);
	}
	setup();
}
