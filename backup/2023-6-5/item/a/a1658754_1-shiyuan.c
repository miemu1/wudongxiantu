// ITEM Made by player(�ɶ�:a1658754_1) /data/item/a/a1658754_1-shiyuan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 13 21:27:28 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("��Թ[2;37;0m", ({ "shiyuan" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m��Ԩ[2;37;0m���ƶ��ɵ�һ������
������ħ���ˡ���������֮ʱ��������Թ��[2;37;0m
�����Ͽ���һ��С�֣��ɶ�(a1658754_1)
");
	set("value", 50100000);
	set("point", 5500);
	set("material", "silk");
	set("wield_msg", "���ɰ�[2;37;0m\n");
	set("unwield_msg", "���[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
