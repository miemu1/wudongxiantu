// ITEM Made by player(�ٻ�:mmm9999_1) /data/item/m/mmm9999_1-zzz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May  2 07:08:51 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m��ϼ[2;37;0m", ({ "zzz" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;31m����[2;37;0m���ƶ��ɵ�һ������
[31m�����氮����ϼ����֪�����ģ���Ҳ��֪��ȥ�δ�[2;37;0m
�����Ͽ���һ��С�֣��ٻ�(mmm9999_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[31m��������ٸ���һ�λ��ᣬ��Ҫ����ħ�䣬���һ���ɽһ���徻[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
