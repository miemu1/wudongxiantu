// gangjian.c

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("Ӱ��", ({ "sword" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����а�����۶��ɵ�һ������\n");
		set("no_get", 1);
		set("material", "а��");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(10);
	setup();
}
