// ITEM Made by player(�������:a304374772_1) /data/item/a/a304374772_1-sqfmxz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar  6 01:13:01 2023
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��ǧ����Ь��[2;37;0m", ({ "sqfmxz" }));
	set_weight(300);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ˫ѥ�ӡ�

[1;36m�鲻������
[1;36m�ִ���һ��
[1;36m�Բ����㾡
[1;36mη����޳�[2;37;0m
ѥ��Ե�Ͽ���һ��С�֣��������(a304374772_1)
");
	set("value", 200100000);
	set("point", 4000);
	set("material", "silk");
	set("wear_msg", "\n[1;36mׯ�������Ժ���\n[1;36m���۴����жž�[2;37;0m\n");
	set("remove_msg", "\n[1;36m���뽭����ˮ·\n[1;36m�о�����\n[1;36m����������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
