// ITEM Made by player(���޹ŵ�:s7787888_1) /data/item/s/s7787888_1-mujian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Apr  4 13:03:27 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("ľ��[2;37;0m", ({ "mujian" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;31m����[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣����޹ŵ�(s7787888_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
