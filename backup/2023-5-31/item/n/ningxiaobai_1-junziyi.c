// ITEM Made by player(����Ⱥ:ningxiaobai_1) /data/item/n/ningxiaobai_1-junziyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 01:46:10 2023
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("������[2;37;0m", ({ "junziyi" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����˿[2;37;0m���ƶ��ɵ�һ��ս�¡�
ս��Ե�Ͽ���һ��С�֣�����Ⱥ(ningxiaobai_1)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "silk");
	set("wear_msg", "[33m$N[33mװ��������[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m�����˾�����[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
