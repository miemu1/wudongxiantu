// ITEM Made by player(�����:xuanwenjian_1) /data/item/x/xuanwenjian_1-zhenhun.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Apr  3 18:08:55 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m���[1;36m��[2;37;0m", ({ "zhenhun" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;35m����[2;37;0m���ƶ��ɵ�һ������
[1;31mһ���۷�ħ��������ɱ��ֱ�����ǣ�ɱ������ɢ�������������ɱ�⣬һ��С�ľͻ���Ϊɱ¾����������ʱɱ��������������棬һ��������ɽ��������������ݣ�ɱ�����죬��������[2;37;0m
�����Ͽ���һ��С�֣������(xuanwenjian_1)
");
	set("value", 2700000);
	set("point", 286);
	set("material", "magic stone");
	set("wield_msg", "[1;31m�����������Ը�����[1;33m��֮�ƿ��ռ���аγ�һ��ɢ����������ɱ��������ħ��[2;37;0m\n");
	set("unwield_msg", "[1;31m�����أ�������һ��[1;33m����ɱ��������ħ����ɱ�������������ε���Ѫ��ɢ������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
