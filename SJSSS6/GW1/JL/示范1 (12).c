// ITEM Made by player(���:fengfeng) /data/item/f/fengfeng-bootsa.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 22 18:24:52 2014
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m[42m����ѥ[2;37;0m", ({ "bootsa" }));
	set_weight(600);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;35m����֮��[2;37;0m���ƶ��ɵ�һ˫ѥ�ӡ�
");
	set("makeinfo", "[1;31m
���(fengfeng)[1;31m ��Ʒ
[2;37;0m");
	set("value", 6100000);
	set("point", 600);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname");
	set("quality_level", 6);
	set("wear_msg", "[33m$N[33mװ��[33m$n[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[33m$n[33m��[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/avoid_dodge", 1.500000);
	set("armor_prop/dp_power", 1.500000);
	set("armor_prop/reduce_damage", 2.500000);
	set("armor_prop/avoid_poison", 3.000000);
	set("armor_prop/avoid_weak", 2.500000);
	set("armor_prop/avoid_freeze", 2.500000);
	set("armor_prop/avoid_forget", 2.500000);
	set("armor_prop/full_self", 2.500000);
	set("armor_prop/avoid_blind", 2.000000);
	set("armor_prop/max_neili", 10000);
	set("armor_prop/reduce_busy", 2.500000);
	set("armor_prop/research_effect", 12);
	set("armor_prop/avoid_busy", 2.500000);
	set("armor_prop/avoid_defense", 1.500000);
	set("armor_prop/avoid_die", 5);

	setup();
}

string long() { return short() + query("makeinfo") + query("long") + item_long(); }
