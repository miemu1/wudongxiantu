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
	set_name(HIC"双倍点券卡"NOR, ({"jifen ka"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000);
		set("jifeng", 12);
            set("no_sell",1);
		set("unit", "张");
		set("base_unit", "张");
		set("base_weight", 10);
		set("no_put", 1);
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell", 1);
		set("base_value", 10000);
		set("long","这是一张双倍点券卡，可以增加一小时的双倍点券时间(对师门任务有效)。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	object ob1;

	me->apply_condition("db_jifen", 360+me->query_condition("db_jifen"));

	write(YEL"你使用一张"HIC"双倍点券卡"YEL"，顿觉神清气爽、思维敏捷!"NOR"\n");
	add_amount(-1);
	return 1;
}

