// ITEM Made by player(ҹ����:s7787888_1) /data/item/s/s7787888_1-qingw.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Mar 25 22:35:17 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m����[2;37;0m", ({ "qingw" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣�ҹ����(s7787888_1)
");
	set("value", 100100000);
	set("point", 11000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
