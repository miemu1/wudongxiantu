// ITEM Made by player(��ҹ:missed1_1) /data/item/m/missed1_1-missed.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 22 20:19:22 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("���ֵ�[2;37;0m", ({ "missed" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣���ҹ(missed1_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "��˵Ψһ���˺��޲ҵ�����[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
