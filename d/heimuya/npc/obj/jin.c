// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("��˿��", ({ "jin" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		 set("icon","5046");
		set("unit", "��");
		set("material", "cloth");
	set("armor_prop/armor", 8);
	}
	setup();
}

