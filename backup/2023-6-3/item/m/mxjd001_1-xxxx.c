// ITEM Made by player(�쳽ҹ��:mxjd001_1) /data/item/m/mxjd001_1-xxxx.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Mar 26 15:29:48 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m��[1;32m��[1;36m��[2;37;0m", ({ "xxxx" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;31m����[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣��쳽ҹ��(mxjd001_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;35m����������磬�����ĺ�����ˡ�[2;37;0m\n");
	set("unwield_msg", "[1;36m���������ǳ����Σ�Ψ���������ࡣ[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
