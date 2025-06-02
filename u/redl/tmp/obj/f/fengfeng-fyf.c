// ITEM Made by player(���:fengfeng) /data/item/f/fengfeng-fyf.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct  4 11:19:29 2014
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[41;1m[1;33m��Դ����[2;37;0m", ({ "fyf" }));
	set_weight(8000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����쾧[2;37;0m���ƶ��ɵ�һ��������
");
	set("makeinfo", "[1;31m
���(fengfeng)[1;31m ��Ʒ
[2;37;0m");
	set("value", 4100000);
	set("point", 400);
	set("max_consistence", 100);
	set("material", "tian jing");
	set("material_file", "/clone/goods/tianjing");
	set("quality_level", 5);
	set("wear_msg", "[33m$N[33mװ��[33m$n[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[33m$n[33m��[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/max_qi", 4500);
	set("armor_prop/kar", 6);

	setup();
}

string long() { return short() + query("makeinfo") + query("long") + item_long(); }
