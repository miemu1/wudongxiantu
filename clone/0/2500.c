
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
	set_name(HIY"2500奖励" NOR, ({"2500gift"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "感谢您的支持，我们会继续努力！\n");
		set("base_unit", "个");
		set("base_weight", 1);
		set("base_value", 1000);
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
	int i;
	mapping gifts;
	string *list;
	object obj;

	gifts = ([
			"/clone/vip2/dan_chongmai2":11111,	//1无量经书
		"/clone/vip2/dan_chongmai1":11111,
			"/clone/vip2/dan_chongmai3":11111,	//1无量经书
			"/clone/vip2/dan_chongmai4":11111,	//1无量经书
		"/clone/0/shimen1":50,	//极品脉丹
		"/clone/vip2/putao1":11111,			//1葡萄
		"/clone/vip2/dan_jiuzhuan":11111,
			"/clone/aaa/yajin/neili_dan1":20,	//1无量经书
		"/clone/aaa/smczl":25,	//师门卡
		"/clone/0/1000xue":900,    //上帝
		"/clone/tianji1/50jing":20,    //上帝
//		"/clone/qnvip":1,    //上帝
		"/clone/shizhe/yuebing1":80,    //上帝
		"/clone/0/500gj":7,    //上帝
		"/clone/0/yuzhou":3,    //上帝

	]);

	list = keys(gifts);

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("战斗中，不能使用"+ name() +"。\n");

	message_vision("$N打开了一" + query("base_unit") + name() + "。\n", me);
	me->add("vip_box_times",1);
	me->add("yuanbao",600000);
	write(YEL"你获得600000灵石!"NOR"\n");

	log_file(me,"vipbox","第"+me->query("vip_box_times")+"次打开了"+this_object()->short()+"。\n");
	for(i=0;i<sizeof(list);i++)
	{
		obj = new(list[i]);
		if(obj->query_amount())
			obj->set_amount(gifts[list[i]]);
		tell_object(me,"你发现了"+obj->short()+"。\n");
		obj->move(me);
	}
	add_amount(-1);

	return 1;

}
