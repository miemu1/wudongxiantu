// longsword.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�����", ({ "dongy wusd"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���������\n");
		set("value", 2);
		set("material", "steel");
		set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�Żر���\n");
	}
	init_sword(500);
	setup();
}
