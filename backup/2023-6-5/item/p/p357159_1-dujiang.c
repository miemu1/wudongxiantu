// ITEM Made by player(����:p357159_1) /data/item/p/p357159_1-dujiang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar 14 19:49:37 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("�ɽ�[2;37;0m", ({ "dujiang" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;35m����[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣�����(p357159_1)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
