// ITEM Made by player(�ȵ�:a15976738848_1) /data/item/a/a15976738848_1-ming.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Mar 19 23:17:53 2023
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("����֮��[2;37;0m", ({ "ming" }));
	set_weight(400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ��������
һ����һ��ˮ��ɫ�ĸ��ӷ���������ɵ�һ���޴���õ�����֮�ߡ�
���׵ľ��߱��棬��������Ļ��ƺͷ��Ź�����һ����һ���˴�������ת��[2;37;0m
����Ե�Ͽ���һ��С�֣��ȵ�(a15976738848_1)
");
	set("value", 200100000);
	set("point", 8800);
	set("material", "silk");
	set("wear_msg", "��β��ӣ���������õĺ���������һ���ܻ�Ϊ��һ��ģ���ģ�������ʵ�ģ�����ת���ľ޴�Բ�֣���Բ�ֵ����ܣ��и��ָ������������Ŵ���ͬ��δ����[2;37;0m\n");
	set("remove_msg", "���˻ػ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
