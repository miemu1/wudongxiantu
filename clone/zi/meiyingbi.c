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
	set_name(HIY"百万霉运金币"NOR, ({"mei coin"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 0);
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
		
		
	if(me->query("yuanbao") > -20000000){
		if (random(10)<=6){
	me->add("yuanbao",-500000);
	write(YEL"二分之一的概率-50Wyuanbao！"NOR"\n");
	}}
	if(me->query("jifeng") > -20000000){
	if (random(20)<=2){
	me->add("jifeng",-500000);
	write(YEL"二分之一的概率-50Wjifeng！"NOR"\n");
	}}
	if(me->query("tianji1") > -20000000){
	if (random(5)<=4){
	me->add("tianji1",-5000);
	write(YEL"二分之一的概率-5ktianji！"NOR"\n");
	}}
	
	
	
	if (random(40)==1){
	me->add("tianji1",10000);
	write(YEL"恭喜！！40分之1的概率获得了1万天机点！"NOR"\n");
	}


	// me->add("zjvip/all_pay",1000000);
	// write(YEL"获得了1000000个贡献！"NOR"\n");
	add_amount(-1);
	return 1;
}