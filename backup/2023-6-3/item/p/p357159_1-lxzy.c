// ITEM Made by player(����:p357159_1) /data/item/p/p357159_1-lxzy.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Apr 11 20:14:36 2023
#include <ansi.h>
#include <weapon.h>

inherit THROWING;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m����׷��[2;37;0m", ({ "lxzy" }));
	set_weight(2);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;31m����[2;37;0m���ƶ��ɵ�һ��������
[1;33m�ǳ�[1;31m����[1;33m��֮һ����ʮ����[2;37;0m
�������Ͽ���һ��С�֣�����(p357159_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_throwing(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
