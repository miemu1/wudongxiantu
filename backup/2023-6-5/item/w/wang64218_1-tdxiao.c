// ITEM Made by player(����:wang64218_1) /data/item/w/wang64218_1-tdxiao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar 21 23:25:28 2023
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m��[30m��[2;37;0m��[2;37;0m", ({ "tdxiao" }));
	set_weight(150);
	set("item_make", 1);
	set("unit", "֧");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ֧�
����Ͽ���һ��С�֣�����(wang64218_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ֧[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
