// ITEM Made by player(����Ⱥ:ningxiaobai_1) /data/item/n/ningxiaobai_1-junzidao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 01:55:37 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("���ӵ�[2;37;0m", ({ "junzidao" }));
	set_weight(7500);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[37m�Ϲź���[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣�����Ⱥ(ningxiaobai_1)
");
	set("value", 1500000);
	set("point", 154);
	set("material", "steel");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
