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
	set_name(HIY"五一奖励"NOR, ({"wuyi jiangli"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 10);
        set("no_sell",1);
        set("give",1);
		set("put", 1);
		set("drop",1);
        set("get",1);
		set("no_auto_get",1);
		set("unit", "枚");
		set("base_unit", "枚");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","清理垃圾的奖励。\n");
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
		me->add("yuanbao",100);
	write(YEL"您获得了100灵石；"NOR"\n");
	if (random(4)<=2) {
	me->add("jifeng",200);
	write(YEL"恭喜：二分之一的概率你额外获得了200点券；"NOR"\n");
	}else
	if (random(4)==1){
	me->add("tianji1",1);
	write(YEL"恭喜！！五分之一的概率获得了1天机点！"NOR"\n");
	}

	add_amount(-1);
	return 1;
}