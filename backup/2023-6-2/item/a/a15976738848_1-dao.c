// ITEM Made by player(�ȵ�:a15976738848_1) /data/item/a/a15976738848_1-dao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Mar 11 23:52:11 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("Ԫʼ֤����[2;37;0m", ({ "dao" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ������
[37m�����������ѣ�[37m���ĬĬ[1;36mӯ�ա�
[33m��Ȼ̫�ر����ɡ�[33mһ��ѭ�����ء�
[2;37;0m
�����Ͽ���һ��С�֣��ȵ�(a15976738848_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "Ԫʼ֮������������������С�[2;37;0m\n");
	set("unwield_msg", "�գ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
