// ITEM Made by player(����:qwms_1) /data/item/q/qwms_1-zsj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 27 23:39:06 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("���ǽ�[2;37;0m", ({ "zsj" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;35m����[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣�����(qwms_1)
");
	set("value", 2700000);
	set("point", 286);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
