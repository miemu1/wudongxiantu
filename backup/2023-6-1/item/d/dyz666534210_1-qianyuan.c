// ITEM Made by player(����:dyz666534210_1) /data/item/d/dyz666534210_1-qianyuan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 25 16:29:43 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mǬԪ[2;37;0m", ({ "qianyuan" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ������
[1;33m��ңԶ�Ĺ�ȥһֱ�����������ռ����
[1;36m��������Զ������Ϣ��ս��֮��
[1;31mΪ�����ս
[1;36mΪǰ����ս
[1;33mΪ�����ս��[2;37;0m
�����Ͽ���һ��С�֣�����(dyz666534210_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;33mһ������������[1;37m������񽣽���[2;37;0m\n");
	set("unwield_msg", "[1;34m��ҹ������Զ������[1;33m�������н������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
