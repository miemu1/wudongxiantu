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
	set_name(HIR"【地 狱 箴 言】"NOR, ({"zhengdao diyu book"}));
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
		set("long","【地狱传说】\n");
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

	me->set_skill("badao", me->query_skill("badao",1) + 180);//开天仙经
	me->set_skill("lunhui-sword", me->query_skill("lunhui-sword",1) + 180);//轮回剑
	me->set_skill("yinyangjiuzhuanshierchongtian", me->query_skill("yinyangjiuzhuanshierchongtian",1) + 280);//太始帝经
	me->set_skill("wanmo-futi", me->query_skill("wanmo-futi",1) + 180);//太元帝经

	
	write(YEL"一阵地狱的呼唤声从背后传来。。。"NOR"\n");
	
	add_amount(-1);
	return 1;
}