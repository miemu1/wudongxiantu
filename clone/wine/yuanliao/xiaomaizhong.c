// dangui.c

#include "herb.h"

void create()
{
	set_name(HIY "小麦种" NOR, ({ "xiaomai zhong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是酿酒材料的种子。\n");
		set("base_unit", "捧");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level", 250);
		set("end","/clone/wine/yuanliao/xiaomai");
	}
	setup();
}
