// ITEM Made by player(��ǳ:x15826849760_1) /data/item/x/x15826849760_1-sss.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Mar 22 08:33:43 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m��[1;31mѩ[1;32m��[2;37;0m", ({ "sss" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;31m����[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣���ǳ(x15826849760_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
