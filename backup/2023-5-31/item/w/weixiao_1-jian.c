// ITEM Made by player(΢Ц:weixiao_1) /data/item/w/weixiao_1-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 21:18:18 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m�����Ȫ��[1;31m[2;37;0m", ({ "jian" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ������
��������»�Ȫ[2;37;0m
�����Ͽ���һ��С�֣�΢Ц(weixiao_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "һ�����绮��[2;37;0m\n");
	set("unwield_msg", "һ����â�ع齣��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
