
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
	set_name(HIC"师门多倍礼包" NOR, ({"shimen1 gift"}));
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
//			"/clone/aaa/yajin/neili_dan1":1,	//1无量经书
//		"/clone/0/jifen":10,
		"/clone/tianji1/qilin":5,
		"/clone/gift/xuanling":5,	//极品脉丹
		"/clone/vip2/tianling":5,			//1葡萄
//		"/clone/vip2/dan_jiuzhuan":200,
//		"/clone/vip2/putao1":300,
//		"/clone//aaa/smczl":2,	//师门卡
//		"/clone/baoshi/god_eyes":1,    //上帝
	]);

	list = keys(gifts);

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("战斗中，不能使用"+ name() +"。\n");

	message_vision("$N打开了一" + query("base_unit") + name() + "。\n", me);
	me->add("vip_box_times",1);
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
