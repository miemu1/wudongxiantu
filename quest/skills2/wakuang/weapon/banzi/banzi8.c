#include <ansi.h>
#include <armor.h>

inherit FINGER;
void create()
{
        set_name( "�Ͻ��ָ", ({ "banzi" }) );
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���Ͻ��ָ��\n");
		set("armor_prop/unarmed_damage", 300);
 set("value", 3000);
	        set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
        	set("unwield_msg", "$N�����ϵ�$n���뻳�С�\n");
	}
	//init_ring(300);
	setup();
}
