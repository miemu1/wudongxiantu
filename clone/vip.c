inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIR"月卡"NOR, ({"month card"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 1000000);
		set("yuanbao", 200);
		set("unit", "张");
		set("long","这是一张月卡，"ZJURL("cmds:use week card")ZJSIZE(20)"使用"NOR"之后增加30天听雨阁时间!\n");
        set("no_sell",1);
	}
}

void init()
{
    if (environment()==this_player())
    	add_action("on_used","use");
}

int on_used(string arg)
{
    int tingyvge;
	object me=this_player();
	
    tingyvge=30 * 24 * 3600;
	
	if (arg!="week card")
      	return notify_fail("你要用什么?\n");  

	write(YEL"你的会员时间增加30天！"NOR"\n");
	me->add("tingyvge",tingyvge);
	me->save();
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }
