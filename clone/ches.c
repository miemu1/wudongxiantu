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
	set_name(HIR"屎"NOR, ({"shi"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("jifeng", 12);
		set("no_put", 1);
		set("channel_id", "新闻");
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell", 1);
            set("no_sell",1);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 100);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int sui,ji,liwu;
	object jingsha;
	sui=random(1000);
	me->set("shfdaskjdfh",sui);
	ji=me->query("shfdaskjdfh",1);
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	//jingsha = new("/clone/gift/jinsha");
	//jingsha->set_amount(ji);
	//jian->move(me);
	//me->add("jifeng",ji);
	CHANNEL_D->do_channel( this_object(), "chat","据说"+me->query("name")+"打开了一个红包获得了"HIR+ji+NOR"个空气！");

      
	add_amount(-1);
	return 1;
}