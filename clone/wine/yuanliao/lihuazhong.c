// dangui.c

#include "herb.h"

void create()
{
	set_name(HIG "梨树苗" NOR, ({ "lihua zhong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是酿酒材料的种苗。\n");
		set("base_unit", "根");
		set("base_value", 5000);
		set("base_weight", 70);
		set("level", 150);
		set("end","/clone/wine/yuanliao/lihua");
	}
	setup();
}
