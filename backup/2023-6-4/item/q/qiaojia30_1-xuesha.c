// ITEM Made by player(����:qiaojia30_1) /data/item/q/qiaojia30_1-xuesha.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed May  3 17:50:50 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("Ѫɱ��[2;37;0m", ({ "xuesha" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;31m����[2;37;0m���ƶ��ɵ�һ������
�˽�һ����Χ��ʱ����ѪɫŨ����Ũ��ɢ�������ֳ�����֮�����������[2;37;0m
�����Ͽ���һ��С�֣�����(qiaojia30_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "����ȥ�������ʧ������һ�ѽ�����ʹ���ߴ����޾���������[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
