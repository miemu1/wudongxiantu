// ITEM Made by player(�ȵ�:a15976738848_1) /data/item/a/a15976738848_1-lup.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Mar 16 14:06:25 2023
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("����«��[2;37;0m", ({ "lup" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ�Ż��ס�
[33m���Ĳ���[1;32m«��١�
[1;36m�ܶ���ʼ��ѭ������
[1;31m��������Ҳ������Ŷ��Ҳ�Ϣ��[2;37;0m
����Ե�Ͽ���һ��С�֣��ȵ�(a15976738848_1)
");
	set("value", 200100000);
	set("point", 17600);
	set("material", "silk");
	set("wear_msg", "[33m���Ĳ���[1;32m«��١�\n[1;36m�ܶ���ʼ��ѭ������\n[1;31m��������Ҳ������Ŷ��Ҳ�Ϣ��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m����������«��[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
