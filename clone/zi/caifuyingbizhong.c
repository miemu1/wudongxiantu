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
	set_name(HIY"财富金币（中）"NOR, ({"xiaowealth coin"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 45);
        set("no_sell",1);
        set("give",1);
		set("put", 1);
		set("drop",1);
        set("get",1);
		set("unit", "枚");
		set("base_unit", "枚");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","一枚硬币都有正反面。\n");
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
	
	write(YEL"你使用了一枚"+name()+YEL+"："NOR"\n");
	me->add("zhanling/a5",200);
	write(YEL"获得了200战令修为！"NOR"\n");
	me->add("yuanbao",50000);
	write(YEL"您获得了保底5万灵石；"NOR"\n");
	me->add("tianji1",5);
	write(YEL"您获得了保底5天机点；"NOR"\n");
	if (random(10)<=2) {
	me->add("jifeng",50000);
	write(YEL"恭喜：十分之三的概率你额外获得了5万点券；"NOR"\n");
	}else
	if (random(20)<=1){
	me->add("tianji1",500);
	write(YEL"恭喜！！十分之一的概率获得了五百天机点！"NOR"\n");
	}

	add_amount(-1);
	return 1;
}