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
	set_name(HIR"【溟毒魔经】", ({"mdmjs book"}));	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 125);
        set("no_sell",1);
        set("give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "本");
		set("base_weight", 1);
		set("base_value", 100);
		set("long"," 九幽炼狱之毒经！\n");
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
if(me->query_skill("mingdu-mojing") > 600)
			return notify_fail("你等级太高了已经无法提升了。\n");
		else {
	me->set_skill("mingdu-mojing", me->query_skill("mingdu-mojing",1) + 25);
	write(YEL"你学会了溟毒魔经"NOR"\n");
	write(YEL"九幽之毒，中则必死！"NOR"\n");
	
	add_amount(-1);
        return 1;}
}