// ITEM Made by player(�������:a304374772_1) /data/item/a/a304374772_1-sqfmhw.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar  6 01:20:18 2023
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��ǧ���λ���[2;37;0m", ({ "sqfmhw" }));
	set_weight(250);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ�Ի���

[1;36m�鲻������
[1;36m�ִ���һ��
[1;36m�Բ����㾡
[1;36mη����޳�[2;37;0m
����Ե�Ͽ���һ��С�֣��������(a304374772_1)
");
	set("value", 200100000);
	set("point", 2500);
	set("material", "silk");
	set("wear_msg", "\n[1;36mׯ�������Ժ���\n[1;36m���۴����жž�[2;37;0m\n");
	set("remove_msg", "\n[1;36m���뽭����ˮ·\n[1;36m�о�����\n[1;36m����������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/whip", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
