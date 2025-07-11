
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
	set_name("续气盘", ( {"xuqi pan"}));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一只续气盘，可以补满当前内力，200w修为之前无限次使用。\n");
		set("unit", "只");
		set("base_unit", "只");
		set("base_weight", 1);
		set("base_value", 10);
		set("jifeng", 200);
		set("no_sell", 1);
		set("no_put", 1);
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->query_enemy()&&sizeof(filter_array(me->query_enemy(),(: userp :))))
		return notify_fail("正在和玩家对手战斗，不能使用"+ name() +"。\n");

	if (me->query("combat_exp")>2000000)
		return notify_fail("已超出修为限制，不能使用"+ name() +"。\n");

	if (me->query("meili") >= me->query("max_neili"))
		return notify_fail("你现在不需使用"+ name() +"。\n");
	else
	{
		me->set("neili",me->query("max_neili"));

		message_vision("$N使用了一下" + name() + "，顿时内息恢复了。\n", me);
		me->start_busy(1);

		return 1;
	}

}
