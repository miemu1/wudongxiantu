// dangui.c

#include "herb.h"

void create()
{
	set_name(HIR "������" NOR, ({ "putao zhong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������Ʋ��ϵ����硣\n");
		set("base_unit", "��");
		set("base_value", 1000);
		set("base_weight", 70);
		set("level", 25);
		set("end","/clone/wine/yuanliao/putao");
	}
	setup();
}
