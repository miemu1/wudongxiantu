// ITEM Made by player(�˷���:qwe1234_1) /data/item/q/qwe1234_1-ting.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar  6 10:42:55 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("��Īͣ[2;37;0m", ({ "ting" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣��˷���(qwe1234_1)
");
	set("value", 1);
	set("point", 50000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
