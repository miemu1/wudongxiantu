// ITEM Made by player(����:mxjd001_1) /data/item/m/mxjd001_1-oooo.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar 28 22:08:14 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m��[1;35m��[30m����[2;37;0m", ({ "oooo" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;31m����[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣�����(mxjd001_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;36m������˼��ε�����ȸ����η����������ѿյ��������ü�˭��������������������������������ˡ��ڰ���������ޣ������ɴ�����[2;37;0m\n");
	set("unwield_msg", "[1;33m�·����ͣ��������ˡ�����������˺���˰��飬ֹͣ��������Ҳ�����￴��������͸һ������Ҳ��һ��֮�ƴ�ճ�һ���ң���α�Ĺ��Ʊ���죬�����㹻������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
