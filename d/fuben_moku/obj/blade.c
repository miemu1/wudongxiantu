#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("Ӱ��", ({ "blade" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����а�����۶��ɵ�һ�ѵ���\n");
		set("no_get", 1);
		set("material", "а��");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(10);
	setup();
}
