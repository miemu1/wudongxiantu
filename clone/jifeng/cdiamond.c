// cdiamond.c ��ʯ����

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIW "��ʯ����" NOR, ({ "chipped diamond" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW "һ���������������������С����ʯ������"NOR"\n");
		set("base_value", 20000);
		set("base_weight", 1);
		set("base_unit", "��");
		set("can_be_enchased", "/clone/gift/diamond");
		set("enchased_need", 3);
		set("jifeng", 12);
		set("no_put", 1);
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell", 1);
		set("magic/type", "lighting");
		set("magic/power", 30);
	}
	set_amount(1);
	setup();
}
