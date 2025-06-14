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
	set_name(HIY"古神通宝（残缺）"NOR, ({"gushen tombo can"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1",300);
        set("no_sell",1);
        set("give",1);
		set("put", 1);
		set("drop",1);
        set("get",1);
		set("unit", "枚");
		set("base_unit", "枚");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","因为是残缺的所以不知道会发生什么事，感觉不会有坏事！\n");
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
		
	write(YEL"你使用了一枚残缺古钱，古钱化作金光缠绕周身！"NOR"\n");
	if ((me->query("potential")-me->query("potential"))>500000000)
                return notify_fail("你的潜能太多了");
      else {
	  me->add("potential",500000);//潜能
	write(HIM"你获得了五十万潜能！"NOR"\n");}
	if ((me->query("combat_exp")-me->query("combat_exp"))>500000000)
		return notify_fail("你的修为太多了");
      else 
	if (random(9)<=2) {
		me->add("combat_exp",50000000);//修为
		write(HIM"恭喜：十分之三的概率你提高了五千万修为!"NOR"\n");
		}
		if ((me->query("magic_points")-me->query("magic_points"))>500000000)
		return notify_fail("你的灵慧太多了");
      else 
	if (random(9)==1){
	me->add("magic_points",5000000);//灵慧
	write(HIM"恭喜：十分之一的概率你提高了五百万灵慧!"NOR"\n");
	}
	if (random(4)==1) {
            me->add("per",1);
			message_vision(HIW"只见$N身上发出一道耀眼的白光，似乎发生了什么神奇的事情。"NOR"\n", me);
            write(HIM"恭喜：你的先天容貌提升了!"NOR"\n");
            }
			
			
	add_amount(-1);
	return 1;
}