// ITEM Made by player(����:makepojson_1) /data/item/m/makepojson_1-bvvgv.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Mar 17 21:46:26 2023
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("����[2;37;0m", ({ "bvvgv" }));
	set_weight(1500);
	set("item_make", 1);
	set("unit", "֧");
	set("long", "������[37m�Ϲź���[2;37;0m���ƶ��ɵ�һ֧�
����Ͽ���һ��С�֣�����(makepojson_1)
");
	set("value", 1500000);
	set("point", 154);
	set("material", "steel");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ֧[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
