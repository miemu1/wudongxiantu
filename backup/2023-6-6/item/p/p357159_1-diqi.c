// ITEM Made by player(����:p357159_1) /data/item/p/p357159_1-diqi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 27 22:12:29 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m����[2;37;0m", ({ "diqi" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;31m����[2;37;0m���ƶ��ɵ�һ������
[1;33m������ȥƽƽ���棬�������[1;31m����[1;33mȴ����עĿ��һ�������Ľ���ɢ��������Ĺ��[2;37;0m
�����Ͽ���һ��С�֣�����(p357159_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "$n�������ʣ���ʱ�������������������г���������������̾Ϊ��ֹ[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
