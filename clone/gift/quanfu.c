
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
	set_name("老魔礼包", ({"jian libao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "小礼包！\n");
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
	object gong,bagua,jiuzhuan;

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");
	
	if (! me->query("born"))
return notify_fail("你还没有出生呢！不能领取礼包\n");

	if (me->is_fighting())
		return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	

	message_vision("$N打开了一" + query("unit") + name() + "。\n", me);
	



	gong = new("/clone/vip3/kuilei");
	write(YEL"恭喜您：获得了"+gong->short()+"。"NOR"\n");
	gong->move(me);
	bagua = new("/clone/aaa/vip2/dan_jiuzhuan");
	bagua->set_amount(6);
	write(YEL"恭喜您：获得了"+bagua->short()+"。"NOR"\n");
	bagua->move(me);
	bagua = new("/clone/vip3/putao1");
	bagua->set_amount(50);
	write(YEL"恭喜您：获得了"+bagua->short()+"。"NOR"\n");
	bagua->move(me);
	bagua = new("/clone/jifeng/book_wuliang");
	bagua->set_amount(40);
	write(YEL"恭喜您：获得了"+bagua->short()+"。"NOR"\n");
	bagua->move(me);
	bagua = new("/clone/vip3/dan_chongmai1");
	bagua->set_amount(88);
	write(YEL"恭喜您：获得了"+bagua->short()+"。"NOR"\n");
	bagua->move(me);
	add_amount(-1);
	me->save();

	return 1;
}
