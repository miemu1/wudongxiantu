// cdiamond.c ��ʯ����

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HBRED "��Ʒ��ҡ���Ƭ" NOR, ({ "wnptc2	sp" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW "����6Ƭ����Ʒ��ҡ���Ƭ�����ɺϳ�1����Ʒ��ң�"NOR"\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "Ƭ");
		set("can_be_enchased", "/clone/GMwupin/GMSSS47");
		set("enchased_need", 6);
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
