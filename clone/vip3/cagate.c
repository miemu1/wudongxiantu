// cagate.c ��觲�Ƭ

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIR "��觲�Ƭ" NOR, ({ "chipped agate" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIR "һƬ�������Ƭ������΢���ĺ�⡣"NOR"\n");
		set("base_value", 20000);
		set("base_weight", 1);
		set("jifeng", 32);
		set("no_put", 1);
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell", 1);
		set("base_unit", "��");
		set("can_be_enchased", "/clone/gift/agate");
		set("enchased_need", 3);
		set("magic/type", "fire");
		set("magic/power", 30);
	}
	set_amount(1);
	setup();
}
