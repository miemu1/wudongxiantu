// ITEM Made by player(�ɶ�:a1658754_1) /data/item/a/a1658754_1-lingdao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Mar 15 00:33:22 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("�鵶[2;37;0m", ({ "lingdao" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;33m����[35m��ʯ[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣��ɶ�(a1658754_1)
");
	set("value", 12100000);
	set("point", 1320);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
