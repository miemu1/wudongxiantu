// ITEM Made by player(�ɶ�:a1658754_1) /data/item/a/a1658754_1-wujinxue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar 14 02:19:37 2023
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("�ڽ�ѥ[2;37;0m", ({ "wujinxue" }));
	set_weight(1080);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[33m�ڽ�˿[2;37;0m���ƶ��ɵ�һ˫ѥ�ӡ�
ѥ��Ե�Ͽ���һ��С�֣��ɶ�(a1658754_1)
");
	set("value", 1500000);
	set("point", 61);
	set("material", "silk");
	set("wear_msg", "[33m$N[33mװ���ڽ�ѥ[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m�������ڽ�ѥ[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
