// ITEM Made by player(���޹ŵ�:s7787888_1) /data/item/s/s7787888_1-czheng.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Apr  5 10:58:32 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m��������[2;37;0m", ({ "czheng" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;31m����[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣����޹ŵ�(s7787888_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
