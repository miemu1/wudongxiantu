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
	set_name(HIY"点券"NOR, ({"jifeng piao"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("yuanbao", 1);
        set("no_sell",1);
        set("no_give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "张");
		set("base_unit", "张");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","这是一张灵石，可以兑换成点券。\n");
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
	write(YEL"你使用了一张"+name()+YEL+"："NOR"\n");
	me->add("jifeng",1);
	write(YEL"获得了1个点券；"NOR"\n");
	//me->add("yuanbao",1000);
	//write(YEL"获得了0个灵石；"NOR"\n");
	//me->add("zjvip/all_pay",0);
//	write(YEL"获得了1个贡献！"NOR"\n");
	

	add_amount(-1);
	return 1;
}