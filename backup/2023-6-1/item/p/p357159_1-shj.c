// ITEM Made by player(����:p357159_1) /data/item/p/p357159_1-shj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Mar 25 21:49:00 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m���[2;37;0m", ({ "shj" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ������
[1;31m��������ѽ��ܲ��꣬���ƺ��ֺ���ͨ[2;37;0m
�����Ͽ���һ��С�֣�����(p357159_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;31m$n����������Χ��ʱ����һ˿���⣬��о�������΢΢����[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
