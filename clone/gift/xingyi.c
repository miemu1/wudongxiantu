
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
	set_name(HIR "定情信物" NOR, ({ "dingqing xingwu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "用来送给心爱的人的礼物。\n");
		set("unit", "张");
		set("base_unit", "张");
		set("base_value", 500);
		set("jifeng", 1000);
		set("no_put", 1);
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell", 1);
		set("only_do_effect", 1);
		set("base_weight", 10);
	}
	setup();
}

void init()
{
	add_action("change_name","xinai");
}

int change_name(string arg)
{
	string ceshi;
	object me=this_player();

	

	if(!arg||arg=="")
	{
		tell_object(me,INPUTTXT("你想送给谁？","xinai $txt#\n"));
		return 1;
	}

	
		write("心意已发出！\n");

	me->set("love",arg);
	add_amount(-1);

	return 1;
}

int do_effect(object me)
{
	change_name("");
	return 1;
}
