inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIR"灵石周卡"NOR, ({"bj card"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		//set("value", 1000000);
		set("gonglao", 30);
		set("unit", "张");
		set("long","这是一张灵石周卡，用了一天可以领720的灵石，"ZJURL("cmds:use week card")ZJSIZE(20)"使用"NOR"之后增加7天会员时间!\n");
            set("no_sell",1);
            set("no_give",1);
            set("no_drop",1);
            //set("no_put",1);
		set("only_do_effect", 1);
		set("suit_point",300);
				set("tianji1", 5);
				

	}
}

void init()
{
    if (environment()==this_player())
    	add_action("on_used","use");
}

int on_used(string arg)
{
    int vip_time;
	object me=this_player();
	
    vip_time=7 * 24 * 3600;
	
	if (arg!="week card")
      	return notify_fail("你要用什么?\n");  

	write(YEL"你的有7天时间可以领取灵石！"NOR"\n");
	me->add("ybvip/times",vip_time);
	me->save();
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }
