inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIY"����Ǳ������"NOR, ({"chaoji card"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		//set("value", 1000000);
		set("gonglao", 30);
		set("unit", "��");
	    set("tianji1", 1200);
		set("give",1);
		set("put", 1);
		set("drop",1);
        set("get",1);
		set("long","����Ǳ���¿���"ZJURL("cmds:use week card")ZJSIZE(20)"ʹ��"NOR"֮������ʮ���Աʱ��!\n");
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
    int vip_time;
	object me=this_player();
	
    vip_time=30 * 24 * 3600*12*10;
	
	if (arg!="week card")
      	return notify_fail("��Ҫ��ʲô?\n");  

	write(YEL"���Ǳ�ܻ�Աʱ������ʮ�꣡"NOR"\n");
	me->add("qnvip/times",vip_time);
	me->save();
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }
