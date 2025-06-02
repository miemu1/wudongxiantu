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
	set_name(HIC"静心丸【绑】"NOR, ({"jingxin wan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000);
		set("yuanbao", 10);
        set("no_sell",1);
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 10000);
		set("long","这是一颗静心丸，可以增加一小时的双倍时间(对闭关室有效)。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	object ob1;

	me->apply_condition("jingxin_exp", 360+me->query_condition("jingxin_exp"));

	write(YEL"你服下一了颗"HIC"静心丸。"NOR"\n");
	add_amount(-1);
	return 1;
}