// ITEM Made by player(��ҹ:missed1_1) /data/item/m/missed1_1-jjskkj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 22 20:16:47 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("ɴ��[2;37;0m", ({ "jjskkj" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣���ҹ(missed1_1)
");
	set("value", 200100000);
	set("point", 10000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
