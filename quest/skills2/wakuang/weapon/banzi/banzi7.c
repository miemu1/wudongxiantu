#include <ansi.h>
#include <armor.h>

inherit FINGER;
void create()
{
        set_name( "ǧ�꺮����ָ", ({ "banzi" }) );
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ǧ�꺮����ָ��\n");
		set("armor_prop/unarmed_damage", 280);
 set("value", 2000);
	        set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
        	set("unwield_msg", "$N�����ϵ�$n���뻳�С�\n");
	}
	//init_ring(280);
	setup();
}
