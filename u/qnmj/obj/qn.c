// shenliwan.c 神力丸

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "潜能果实小" NOR, ({ "dan", "wan"}) );
        set_weight(200);
		set("no_drop", "这样东西不能离开你。\n");
		set("no_give", "这样东西不能离开你。\n");
		set("no_get", "这样东西不能离开你。\n");
		set("no_put", "这样东西不能离开你。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗圆圆的神力丸，据说吃了可以提升潜能。\n");
                set("xy_money", 1);

                set("unit", "颗");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
int b,lvl;
lvl=me->query("level");
b= 400000+random(50000) + (400000+random(50000)*lvl)/10;
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
if (me->query("potential") < me->query_potential_limit() && me->query_skill("martial-cognize", 1) >= 400)	
{
	
      me->add("potential", b);
	tell_object(me, HIC "\n你获得了" + chinese_number(b) + "点潜能。"NOR"\n");
     destruct(this_object());
	      return 1;
	 }
             tell_object(me, HIC "\n你 武学修养低于400或者是你的潜能已满"NOR"\n");
        destruct(this_object());
        return 1;
}

