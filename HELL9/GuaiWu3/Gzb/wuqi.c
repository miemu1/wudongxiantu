// longsword.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�ڵ�����ѩ", ({ "heidao chuixue"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѻڵ���\n");
		set("value", 2);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_sword(3000);
	setup();
}
