// ITEM Made by player(�������:a304374772_1) /data/item/a/a304374772_1-sqfmzt.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Mar  9 13:03:54 2023
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��ǧ��ָ��[2;37;0m", ({ "sqfmzt" }));
	set_weight(175);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ��ָ�ס�

[1;36m�鲻������
[1;36m�ִ���һ��
[1;36m�Բ����㾡
[1;36mη����޳�[2;37;0m
ָ��Ե�Ͽ���һ��С�֣��������(a304374772_1)
");
	set("value", 200100000);
	set("point", 10000);
	set("material", "silk");
	set("wear_msg", "\n[1;36mׯ�������Ժ���\n[1;36m���۴����жž�[2;37;0m\n");
	set("remove_msg", "\n[1;36m���뽭����ˮ·\n[1;36m�о�����\n[1;36m����������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
