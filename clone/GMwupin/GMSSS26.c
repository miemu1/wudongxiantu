
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
	set_name(HIC "天清玉髓" NOR, ({"feicui lanS"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "滴");
		set("base_unit", "滴");
		set("long", "这是一滴万年难得一见的天清玉髓，据说能解百毒。\n");
		set("no_sell", 1);
		set("value", 100);
		set("base_value", 100);
		set("base_weight", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	me->set_temp("nopoison", 3);
	me->set("eff_jing", me->query("max_jing"));
	me->set("jing", me->query("max_jing"));
	message_vision("$N把" + name() + "扔进嘴里，几下就吞了下去。\n", me);
	tell_object(me, HIG "\n你只觉一股清香沁入心肺，顿时灵台一片空明，神意清爽！"NOR"\n");
	add_amount(-0);
	return 1;
}

