// ITEM Made by player(�������:a304374772_1) /data/item/a/a304374772_1-sqfmd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar  7 17:05:53 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��ǧ���ε�[2;37;0m", ({ "sqfmd" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����[2;37;0m���ƶ��ɵ�һ�ѵ���

[1;36m��ɢ�쳾���޼�
[1;36m���԰�����ľ��
[1;36m˪Ҷ�轣���Ƽ�
[1;36m��������л���
[1;36m������ӳ���ѽ�
[1;36m��Թ����̾�޷�
[1;36mǧ���̲�Ѱ��Ӱ
[1;36m��ħ�������̳�[2;37;0m
�����Ͽ���һ��С�֣��������(a304374772_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "\n[1;36mʮ��ɱһ��\n[1;36mǧ�ﲻ����[2;37;0m\n");
	set("unwield_msg", "\n[1;36m�����Ѿ���\n[1;36mһХ��ǧɽ[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
