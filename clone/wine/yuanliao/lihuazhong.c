// dangui.c

#include "herb.h"

void create()
{
	set_name(HIG "������" NOR, ({ "lihua zhong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������Ʋ��ϵ����硣\n");
		set("base_unit", "��");
		set("base_value", 5000);
		set("base_weight", 70);
		set("level", 150);
		set("end","/clone/wine/yuanliao/lihua");
	}
	setup();
}
