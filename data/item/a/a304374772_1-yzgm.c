// ITEM Made by player(�������:a304374772_1) /data/item/a/a304374772_1-yzgm.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar  6 00:47:12 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��֮��â[2;37;0m", ({ "yzgm" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ������

[1;36m����һɫ���˳�
[1;36m����й�����
[1;36m���Ϻ��˳�����
[1;36m���º��������[2;37;0m
�����Ͽ���һ��С�֣��������(a304374772_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "\n[1;36m�¹�ɫ��Ů����\n[1;36m�����ᣬ��೤\n[1;36m�����£��ı���\n[1;36mǧ�źޣ��ֻس�[2;37;0m\n");
	set("unwield_msg", "[1;36mһ������ҹ\n[1;36m���ƶ�����\n[1;36mб��������\n[1;36m���ݻ��ٻ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
