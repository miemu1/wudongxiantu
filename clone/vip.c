inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIR"�¿�"NOR, ({"month card"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 1000000);
		set("yuanbao", 200);
		set("unit", "��");
		set("long","����һ���¿���"ZJURL("cmds:use week card")ZJSIZE(20)"ʹ��"NOR"֮������30�������ʱ��!\n");
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
      	return notify_fail("��Ҫ��ʲô?\n");  

	write(YEL"��Ļ�Աʱ������30�죡"NOR"\n");
	me->add("tingyvge",tingyvge);
	me->save();
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }
