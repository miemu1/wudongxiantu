// wushuang.c ��˫
 
#include <armor.h>
 
inherit SHIELD;

void create()
{
	set_name(HIR"��˫"NOR, ({ "wu shuang" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��ɽ֮�ۣ�Ⱥ�����棬������˫��������˭��\n");
		set("unit", "��");
		set("value", 1);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_put", 1);
		set("no_steal", 1);
	set("armor_prop/unarmed_damage", 100);
	set("armor_prop/damage", 100);
	set("armor_prop/skills", 100);
	set("armor_prop/armor", 100);
	}
	setup();
}
