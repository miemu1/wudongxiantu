
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
	set_name("老魔开服小礼包", ({"buchang gift"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "开服小礼包老魔礼包，感谢大家对游戏的支持，祝您游戏愉快！\n");
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
		"/clone/shizhe/jinsha":10,
	]);

	list = keys(gifts);

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");
	
	if (! me->query("born"))
return notify_fail("你还没有出生呢！不能领取礼包\n");

	if (me->is_fighting())
		return notify_fail("战斗中，不能使用"+ name() +"。\n");
	if (me->query("buchang_times"))
		return notify_fail("已经使用过了，不能使用"+ name() +"。\n");
	message_vision("$N打开了一" + query("base_unit") + name() + "。\n", me);
	
	me->add("experience", 50000);
	me->add("potential", 50000);
	me->add("buchang_times",1);
	
	log_file("gift_all/buchang", me->query("name")+"("+me->query("id")+")第"
				+me->query("buchang_times")+"次打开了"+this_object()->short()+"   "+ctime(time())+"。\n");
	for(i=0;i<sizeof(list);i++)
	{
		obj = new(list[i]);
		if(obj->query_amount())
			obj->set_amount(gifts[list[i]]);
		tell_object(me, HIR"你发现了"+NOR+obj->short()+NOR"。\n");
		obj->move(me);
	}
	tell_object(me, HIY"你获得了5万点实战体会，5万点潜能。"NOR+HIG"老魔祝你游戏愉快！"NOR"\n");
	add_amount(-1);

	return 1;

}
