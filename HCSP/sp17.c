// cdiamond.c ��ʯ����

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HBRED "���ϱ��䡤��Ƭ" NOR, ({ "sjssa5 sp" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW "����4Ƭ�����ϱ��䡤��Ƭ�����ɺϳ�1�����ϱ��䣡"NOR"\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "Ƭ");
		set("can_be_enchased", "/SJSSS5/BOX/box1");
		set("enchased_need", 4);
		set("yuanbao", 100);
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
