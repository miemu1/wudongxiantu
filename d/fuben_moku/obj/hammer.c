#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("Ӱ��", ({ "hammer" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����а�����۶��ɵ�һ�����ӡ�\n");
		set("no_get", 1);
		set("material", "а��");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_hammer(10);
	setup();
}