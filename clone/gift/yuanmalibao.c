
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
	set_name("源码礼包", ({"yuanma libao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "巫师白的财产！\n");
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 10);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int i,num1,num2,num3,num4;
	object gong,bagua,jian;

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	num1=200000;
	me->add("combat_exp",num1);
	num2=250000;
	me->add("potential",num2);
	//me->add("weiwang",num4);
	me->set("p_master/last_learnto",me->query("combat_exp"));
	//me->add("zjvip/times",72*3600);

	message_vision("$N打开了一" + query("unit") + name() + "。\n", me);
	write(YEL"恭喜您：获得了"+num1+"点修为。"NOR"\n");
	write(YEL"恭喜您：获得了"+num2+"点潜能。"NOR"\n");
	
	/*gong = new("/clone/gift/weiwang");
	write(YEL"恭喜您：获得了"+gong->short()+"。"NOR"\n");
	gong->move(me);*/
	jian = new("/clone/jifeng/dan_wuji");
	jian->set_amount(5);
	write(YEL"恭喜您：获得了"+jian->short()+"。"NOR"\n");
	jian->move(me);
	bagua = new("/clone/jifeng/kuilei");
	bagua->set_amount(3);
	write(YEL"恭喜您：获得了"+bagua->short()+"。"NOR"\n");
	bagua->move(me);

	
	add_amount(-1);
	me->save();

	return 1;
}
