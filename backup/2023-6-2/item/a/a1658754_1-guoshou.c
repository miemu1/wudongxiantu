// ITEM Made by player(����:a1658754_1) /data/item/a/a1658754_1-guoshou.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed May  3 08:24:00 2023
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("����[2;37;0m", ({ "guoshou" }));
	set_weight(225);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ˫���ơ�
����Ե�Ͽ���һ��С�֣�����(a1658754_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wear_msg", "[33m$N[33mװ������[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m�����˹���[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
