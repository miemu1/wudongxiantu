// ITEM Made by player(���ɳ�:w1045575408_1) /data/item/w/w1045575408_1-bxht.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 05:12:14 2023
#include <ansi.h>
#include <armor.h>

inherit PANTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("���Ļ���[2;37;0m", ({ "bxht" }));
	set_weight(700);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����˿[2;37;0m���ƶ��ɵ�һ�����ӡ�
����Ե�Ͽ���һ��С�֣����ɳ�(w1045575408_1)
");
	set("value", 2100000);
	set("point", 110);
	set("material", "silk");
	set("wear_msg", "[33m$N[33mװ�����Ļ���[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m�����˱��Ļ���[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
