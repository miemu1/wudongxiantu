// ITEM Made by player(�ᰮؼ��:cys191_1) /data/item/c/cys191_1-mmd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 25 17:04:36 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35mħ[1;35mħ[31m��[2;37;0m", ({ "mmd" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣��ᰮؼ��(cys191_1)
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
