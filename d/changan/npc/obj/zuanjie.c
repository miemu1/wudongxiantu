//zuanjie.c

#include <armor.h>

inherit FINGER;

void create()
{
	set_name("��ʯ��ָ", ({ "zuan jie", "zuanjie", "ring" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("value", 12000);
		set("material", "diamond");
	set("armor_prop/armor", 1);
	set("armor_prop/personality", 1);
	}

	setup();
}       
