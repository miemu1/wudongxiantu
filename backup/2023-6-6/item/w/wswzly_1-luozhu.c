// ITEM Made by player(����:wswzly_1) /data/item/w/wswzly_1-luozhu.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Mar 18 17:49:12 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[32m����[2;37;0m", ({ "luozhu" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣�����(wswzly_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "$N�����Ժ�Ĵ��̷�������һ��������һ������ɫ���齣[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
