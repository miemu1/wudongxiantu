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
	set_name(HIR"【剑 道 箴 言】"NOR, ({"zhengdao jian book"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 9500000);
        set("no_sell",1);
        set("give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "本");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","【以 剑 证 道】\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+name()+"。\n");

	me->set_skill("liuyue-jian", me->query_skill("liuyue-jian",1) + 180);//玉影流月剑
	me->set_skill("canxin-jian", me->query_skill("canxin-jian",1) + 180);//残心剑
	me->set_skill("lonely-sword", me->query_skill("lonely-sword",1) + 180);//独孤九剑
	me->set_skill("xuantie-jian", me->query_skill("xuantie-jian",1) + 180);//玄铁剑法"
	me->set_skill("chuixue-jian", me->query_skill("chuixue-jian",1) + 180);//寒天吹雪剑法
	
	write(YEL"此间记载的武学为世俗罕见之剑道武学"NOR"\n");
	
	add_amount(-1);
	return 1;
}