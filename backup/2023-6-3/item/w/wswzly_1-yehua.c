// ITEM Made by player(����:wswzly_1) /data/item/w/wswzly_1-yehua.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Apr  8 20:46:16 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m��Ҷ[1;35m�ɻ�[2;37;0m", ({ "yehua" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;31m����[2;37;0m���ƶ��ɵ�һ������
[1;35m�˽�һ���������ʱ���ֳ�һ�����������֣������������Ҷ���仨��ɷ�Ǻÿ�[2;37;0m
�����Ͽ���һ��С�֣�����(wswzly_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;35m$N����һ�У���Ҷ�ɻ������ʱ����[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
