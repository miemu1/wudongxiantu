// dangui.c

#include "herb.h"

void create()
{
	set_name(HIR "高粱种" NOR, ({ "gaoliang zhong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是酿酒材料的种子。\n");
		set("base_unit", "捧");
		set("base_value", 1000);
		set("base_weight", 70);
		set("level", 0);
		set("end","/clone/wine/yuanliao/gaoliang");
	}
	setup();
}
