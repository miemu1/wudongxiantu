inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIR"��ʯ�ܿ�"NOR, ({"bj card"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		//set("value", 1000000);
		set("gonglao", 30);
		set("unit", "��");
		set("long","����һ����ʯ�ܿ�������һ�������720����ʯ��"ZJURL("cmds:use week card")ZJSIZE(20)"ʹ��"NOR"֮������7���Աʱ��!\n");
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
      	return notify_fail("��Ҫ��ʲô?\n");  

	write(YEL"�����7��ʱ�������ȡ��ʯ��"NOR"\n");
	me->add("ybvip/times",vip_time);
	me->save();
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }
