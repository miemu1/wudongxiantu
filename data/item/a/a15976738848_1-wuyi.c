// ITEM Made by player(�ȵ�:a15976738848_1) /data/item/a/a15976738848_1-wuyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Mar 19 23:27:39 2023
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("����[2;37;0m", ({ "wuyi" }));
	set_weight(1000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ��ս�¡�
��Ի��������ͬ��[2;37;0m
ս��Ե�Ͽ���һ��С�֣��ȵ�(a15976738848_1)
");
	set("value", 200100000);
	set("point", 10000);
	set("material", "silk");
	set("wear_msg", "��Ի��������ͬ��[2;37;0m\n");
	set("remove_msg", "���û���·�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
