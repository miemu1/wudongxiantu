// dangui.c

#include "herb.h"

void create()
{
	set_name(HIY "桃核" NOR, ({ "tao zhong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是可以作为种子的桃核，据说在宝昌客栈旁的良田里可以种植出桃子。\n");
		set("base_unit", "枚");
		set("base_value", 10000);
		set("base_weight", 70);
		//set("level",400);
		//set("wine","/clone/wine/monkey");
	}
	setup();
}
