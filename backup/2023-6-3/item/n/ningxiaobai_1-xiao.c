// ITEM Made by player(宁不群:ningxiaobai_1) /data/item/n/ningxiaobai_1-xiao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 03:27:42 2023
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("真君子战衣[2;37;0m", ({ "xiao" }));
	set_weight(1000);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m世界[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：宁不群(ningxiaobai_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备真君子战衣[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了真君子战衣[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
