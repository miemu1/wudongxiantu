// ITEM Made by player(�������:a304374772_1) /data/item/a/a304374772_1-sqfmg.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Mar 11 03:42:08 2023
#include <ansi.h>
#include <weapon.h>

inherit CLUB;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��ǧ���ι�[2;37;0m", ({ "sqfmg" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣��������(a304374772_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_club(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
