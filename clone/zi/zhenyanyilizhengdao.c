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
	set_name(HIR"【证 道 箴 言】"NOR, ({"zhengdao li book"}));
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
		set("long","【以 力 证 道】\n");
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

	me->set_skill("huagu-mianzhang", me->query_skill("huagu-mianzhang",1) + 180);//化骨绵掌
	me->set_skill("fireice-strike", me->query_skill("fireice-strike",1) + 180);//烈焰寒冰掌
	me->set_skill("doomstrike", me->query_skill("doomstrike",1) + 180);//寒天神掌
	me->set_skill("chongyang-shenzhang", me->query_skill("chongyang-shenzhang",1) + 180);//重阳神掌

	
	write(YEL"上面记载的五种武学，最低都是一流招式，最后一门武学非人力所能掌握"NOR"\n");
	
	add_amount(-1);
	return 1;
}