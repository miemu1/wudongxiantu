// ITEM Made by player(ϲ����:oo00_1) /data/item/o/oo00_1-ztt.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Mar  9 11:11:10 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m����[2;37;0m", ({ "ztt" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;35m����[2;37;0m���ƶ��ɵ�һ������
�Ҿ����ң��κ����ﲻ������ƥ�У�������ң�����ң�����������ů�Լ���ҫ���ǹ������ҡ������������ͷ��Լ���[2;37;0m
�����Ͽ���һ��С�֣�ϲ����(oo00_1)
");
	set("value", 2700000);
	set("point", 286);
	set("material", "magic stone");
	set("wield_msg", "���������Ǹ�ɽ����Ϫ��������������֮;ײ����ֹ��Ρ�롣[2;37;0m\n");
	set("unwield_msg", "�����������˽ܶ��ǲݽ棬��ȼ����ԭ֮���˿��貵��Ǻӡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
