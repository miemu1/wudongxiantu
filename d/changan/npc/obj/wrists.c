//wrists.c

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name(HIY"�̽�����"NOR, ({ "liujin wanlian", "wanlian", "wrists" }));
	set("weight", 200);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("value", 5000);
		set("material", "gold");
	set("armor_prop/armor", 1);
	}

	setup();
}
