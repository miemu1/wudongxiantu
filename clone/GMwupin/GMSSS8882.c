// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("��α�����ɵ����־�", ({ "heyd yjs1" }));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ɵ���\n");
		set("value", 10);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(1000);
	setup();
}
