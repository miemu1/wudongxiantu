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
	set_name(HIY"财富金币"NOR, ({"wealth coin"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 15000);
        set("no_sell",1);
        set("no_give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "枚");
		set("base_unit", "枚");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","有个声音告诉你，它充满着机会和运气。\n");
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
	me->add("zhanling/a5",2000);
	write(YEL"获得了2000战令修为！"NOR"\n");
	me->add("yuanbao",100000);
	write(YEL"您获得了保底的10万灵石；"NOR"\n");
	me->add("tianji1",5000);
	write(YEL"您获得了保底5000天机点！"NOR"\n");
	if (random(10)<=2) {
	me->add("jifeng",100000);
	write(YEL"恭喜：十分之三的概率你额外获得了10万点券；"NOR"\n");
	}else
	if (random(30)<=1){
	me->add("tianji1",100000);
	write(YEL"恭喜！！30分之1的概率获得了十万天机点！"NOR"\n");
	}
	// me->add("zjvip/all_pay",1000000);
	// write(YEL"获得了1000000个贡献！"NOR"\n");
	add_amount(-1);
	return 1;
}