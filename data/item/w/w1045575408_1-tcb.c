// ITEM Made by player(���ɳ�:w1045575408_1) /data/item/w/w1045575408_1-tcb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 05:17:03 2023
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("��ϱ�[2;37;0m", ({ "tcb" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����˿[2;37;0m���ƶ��ɵ�һ���ޡ�
�ޱ��Ͽ���һ��С�֣����ɳ�(w1045575408_1)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
