// ITEM Made by player(����:bllm_1) /data/item/b/bllm_1-ren.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 23 10:49:24 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m��[1;31m��[1;35m����[2;37;0m", ({ "ren" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ�ѵ���
[1;32m�洦�ɼ���ׯ԰���������[1;35m��Щ���𣬻��У�[1;31mѪ�գ�[2;37;0m
�����Ͽ���һ��С�֣�����(bllm_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
