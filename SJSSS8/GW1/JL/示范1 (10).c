// ITEM Made by player(����:fengfeng) /data/item/f/fengfeng-fyb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct  4 11:26:42 2014
#include <ansi.h>
#include <armor.h>

inherit FINGER;
inherit F_ITEMMAKE;

void create()
{
	set_name("[41;1m[1;33m�𵤡�ָ��[2;37;0m", ({ "fyb" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;35m��ʯ[2;37;0m���ƶ��ɵ�һ��ָ�ס�
");
	set("makeinfo", "[1;31m
����(fengfeng)[1;31m װ��
[2;37;0m");
	set("value", 10);
	set("point", 500);
	set("max_consistence", 100);
	set("material", "magic stone");
	set("material_file", "/d/item/obj/GMSSS41");
	set("quality_level", 5);
	set("wear_msg", "[33m$N[33mװ��[33m$n[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[33m$n[33m��[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/kar", 3);
	set("armor_prop/double_damage", 2.000000);
	set("armor_prop/leech_neili", 2.000000);

	setup();
}

string long() { return short() + query("makeinfo") + query("long") + item_long(); }
