// ITEM Made by player(��������:x000127_1) /data/item/x/x000127_1-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 25 18:22:11 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("������[2;37;0m", ({ "sword" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ������
��˵�еĿ�����ӵ�е���������[2;37;0m
�����Ͽ���һ��С�֣���������(x000127_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "ӵ�еĿ�������[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
