// longsword.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("���䵶", ({ "xuanwu dao"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����䵶��\n");
		set("value", 2);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_sword(5000);
	setup();
}
