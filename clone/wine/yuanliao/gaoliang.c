// dangui.c

#include "herb.h"

void create()
{
	set_name(HIR "����" NOR, ({ "gao liang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������Ʋ��ϡ�\n");
		set("base_unit", "��");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level",25);	
		set("wine","/clone/wine/gaoliangjiu");
	}
	setup();
}
