// dangui.c

#include "herb.h"

void create()
{
	set_name(HIW "�滨" NOR, ({ "li hua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������Ʋ��ϡ�\n");
		set("base_unit", "��");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level",225);	
		set("wine","/clone/wine/lihuajiu");
	}
	setup();
}
