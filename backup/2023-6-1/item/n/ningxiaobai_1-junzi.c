// ITEM Made by player(����Ⱥ:ningxiaobai_1) /data/item/n/ningxiaobai_1-junzi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 01:29:02 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("���ӽ�[2;37;0m", ({ "junzi" }));
	set_weight(45000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[36m����[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣�����Ⱥ(ningxiaobai_1)
");
	set("value", 1500000);
	set("point", 154);
	set("material", "steel");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
