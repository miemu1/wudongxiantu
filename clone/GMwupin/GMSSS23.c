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
	set_name(HIR"【斗战圣经】", ({"dzsjs book"}));	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 100);
        set("no_sell",1);
        set("give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "本");
		set("base_weight", 1);
		set("base_value", 100);
		set("long"," 此乃传承斗战胜佛的棍法！\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");
if(me->query_skill("douzhan-shengjing") > 600)
			return notify_fail("你等级太高了已经无法提升了。\n");
		else {
	me->set_skill("douzhan-shengjing", me->query_skill("douzhan-shengjing",1) + 25);
	write(YEL"你学会了斗战圣经！"NOR"\n");
	write(YEL"我若成佛，天下无魔！！！"NOR"\n");
	
	add_amount(-1);
        return 1;}
}