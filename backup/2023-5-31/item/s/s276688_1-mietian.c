// ITEM Made by player(������:s276688_1) /data/item/s/s276688_1-mietian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar  7 19:51:12 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("����[2;37;0m", ({ "mietian" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;35m����[2;37;0m���ƶ��ɵ�һ������
����������Ϫ�����Ǹ�ɽ������������֮;ײ����ֹ��Ρ�롣[2;37;0m
�����Ͽ���һ��С�֣�������(s276688_1)
");
	set("value", 2700000);
	set("point", 286);
	set("material", "magic stone");
	set("wield_msg", "���������ǲݽ�����˽ܣ���ȼ����ԭ֮���˿��貵��Ǻӡ�[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
