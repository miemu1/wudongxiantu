// ITEM Made by player(���ɳ�:w1045575408_1) /data/item/w/w1045575408_1-xtyw.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 05:33:19 2023
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("����һ��[2;37;0m", ({ "xtyw" }));
	set_weight(2250);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[37m�Ϲź���[2;37;0m���ƶ��ɵ�һ˫���ơ�
����������죬ע���������ƶ���[2;37;0m
����Ե�Ͽ���һ��С�֣����ɳ�(w1045575408_1)
");
	set("value", 1500000);
	set("point", 154);
	set("material", "steel");
	set("wear_msg", "ֻ������һ����������ȭ�׾��Ѿ�����������[2;37;0m\n");
	set("remove_msg", "$N����һ�գ�����������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
