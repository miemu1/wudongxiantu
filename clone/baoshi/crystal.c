// crystal.c ˮ��

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIM "ˮ��" NOR, ({ "crystal" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIM "һ���ɫ��ˮ����"NOR"\n");
		set("base_value", 50000);
        set("no_sell",1);
        set("give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "��");
		set("base_weight", 1);
		set("base_value", 100);
		set("can_be_enchased", __DIR__"fcrystal");
		set("enchased_need", 3);
		set("magic/type", "magic");
		set("magic/power", 100);
	}
	set_amount(1);
	setup();
}
