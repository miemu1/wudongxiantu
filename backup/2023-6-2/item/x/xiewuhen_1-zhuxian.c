// ITEM Made by player(л�޺�:xiewuhen_1) /data/item/x/xiewuhen_1-zhuxian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 25 23:56:40 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m���ɽ�[2;37;0m", ({ "zhuxian" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ������
[1;31m�����ں����е�һ�ƹ⣬�˽�ר�˲���֮�������ɽ��������˿��޷���ԭ�������˵���֮�ס���Ϊ�����޴���������֮�ܣ�ʹ�����ײ���ͳ�����µ��뷨�������е�����֮�����ɣ�ɱ¾֮�����ء�[2;37;0m
�����Ͽ���һ��С�֣�л�޺�(xiewuhen_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;31m��ͭ������Ǹ֣���������ɽ�²ء����������ߵ���������ˮ����â��[2;37;0m\n");
	set("unwield_msg", "[1;31m��������¾�����������Ĵ����⡣���ɱ仯�������������ѪȾ��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
