// ITEM Made by player(�������:a304374772_1) /data/item/a/a304374772_1-sqfmyd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar  6 01:22:30 2023
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��ǧ��������[2;37;0m", ({ "sqfmyd" }));
	set_weight(400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ��������

[1;36m�鲻������
[1;36m�ִ���һ��
[1;36m�Բ����㾡
[1;36mη����޳�[2;37;0m
����Ե�Ͽ���һ��С�֣��������(a304374772_1)
");
	set("value", 200100000);
	set("point", 8800);
	set("material", "silk");
	set("wear_msg", "\n[1;36mׯ�������Ժ���\n[1;36m���۴����жž�[2;37;0m\n");
	set("remove_msg", "\n[1;36m���뽭����ˮ·\n[1;36m�о�����\n[1;36m����������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
