// dangui.c

#include "herb.h"

void create()
{
	set_name(HIR "仙桃" NOR, ({ "tao zi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "据说猴子非常喜欢吃桃子之类的鲜果。据说某些猴子会给投缘的人以猴儿酒作为回报。\n");
		set("base_unit", "枚");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level",400);
		set("wine","/clone/wine/monkey");
	}
	setup();
}
