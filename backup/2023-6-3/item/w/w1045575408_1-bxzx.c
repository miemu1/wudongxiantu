// ITEM Made by player(���ɳ�:w1045575408_1) /data/item/w/w1045575408_1-bxzx.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 05:14:44 2023
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("����սѥ[2;37;0m", ({ "bxzx" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;37m����˿[2;37;0m���ƶ��ɵ�һ˫ѥ�ӡ�
ѥ��Ե�Ͽ���һ��С�֣����ɳ�(w1045575408_1)
");
	set("value", 2100000);
	set("point", 88);
	set("material", "silk");
	set("wear_msg", "[33m$N[33mװ������սѥ[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m�����˱���սѥ[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
