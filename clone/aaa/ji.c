//yupei.c
 
#include <armor.h>
 
inherit SHIELD;

void create()
{
	set_name(HIY"��������"NOR, ({ "long fong" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����˫�����������塣\n");
		set("unit", "��");
		set("value", 5000000);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_put", 1);
		set("no_steal", 1);
	set("armor_prop/unarmed_damage", 600);
	set("armor_prop/damage", 600);
	set("armor_prop/armor", 600);
	}
	setup();
}

int query_autoload() {return 1;}