// Ѫ����ʯ

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIM "��ˮ��" NOR, ({ "Ruby gem" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIM "һ��Ѫ��ɫ��ˮ����"NOR"\n");
		set("base_value", 20000);
		set("base_weight", 1);
		set("base_unit", "��");
		set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_teal", 1);
		set("yuanbao", 500);
		set("can_be_inlay",([
		"name":"��ˮ��",
		"skill":"xuehai-mogong",
		])
		);
	}
	set_amount(1);
	setup();
}
