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
	set_name(HIR"【归真道经】"NOR, ({"tianren book"}));	
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
		set("long"," 天地与我并生，万物与我为一，天人相合，如影随形。一本蕴含天人奥义的绝世轻功\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+name() +"。\n");
if(me->query_skill("tianrenheyi") > 350)
			return notify_fail("你等级太高了已经无法提升了。\n");
		else {
	me->set_skill("tianrenheyi", me->query_skill("tianrenheyi",1) + 25);
	write(YEL"你学会了归真道经。。。"NOR"\n");
	write(YEL"天地与我并生，万物与我为一，天人之奥义，尽在此书中"NOR"\n");
	
	add_amount(-1);
        return 1;}
}