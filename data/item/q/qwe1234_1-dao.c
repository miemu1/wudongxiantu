// ITEM Made by player(�˷���:qwe1234_1) /data/item/q/qwe1234_1-dao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar  6 11:17:12 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("ħ��[2;37;0m", ({ "dao" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣��˷���(qwe1234_1)
");
	set("value", 1);
	set("point", 50000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
