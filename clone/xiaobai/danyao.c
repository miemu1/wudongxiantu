
#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload()
{
	return query_amount() + "";
}

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
	set_name("测试丹", ( {"cheshi dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一颗测试丹，可以清除busy，但是会消耗1000血。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 1);
		set("base_value", 10);
		set("no_sell", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{		
		message_vision("$N服下一" + query("unit") + name() + "，顿时内息顺畅许多。\n", me);
		me->start_busy(-101);
		me->add("qi",1000);
		add_amount(-1);
		return 1;	
}
