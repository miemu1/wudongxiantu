
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
	set_name("tap上架礼包", ({"kaihuang libao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "tap上架礼包！\n");
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

	//me->add("jifeng",200);
	
	

	message_vision("$N打开了一" + query("unit") + name() + "。\n", me);
	write(YEL"恭喜您：获得了200点券。"NOR"\n");



	gong = new("/clone/vip3/jiuzhuan");
	write(YEL"恭喜您：获得了"+gong->short()+"。"NOR"\n");
	gong->move(me);
	jian = new("/clone/vip3/putao1");
	jian->set_amount(4);
	write(YEL"恭喜您：获得了"+jian->short()+"。"NOR"\n");
	jian->move(me);
	bagua = new("/clone/vip3/dan_chongmai1");
	bagua->set_amount(29);
	write(YEL"恭喜您：获得了"+bagua->short()+"。"NOR"\n");
	bagua->move(me);
	add_amount(-1);
	me->save();

	return 1;
}
