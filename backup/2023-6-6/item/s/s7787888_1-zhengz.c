// ITEM Made by player(ҹ����:s7787888_1) /data/item/s/s7787888_1-zhengz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Mar 24 01:05:17 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("����[2;37;0m", ({ "zhengz" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m��ħ[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣�ҹ����(s7787888_1)
");
	set("value", 80100000);
	set("point", 8800);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
