// dangui.c

#include "herb.h"

void create()
{
	set_name(HIG "�̶�" NOR, ({ "lv dou" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������Ʋ��ϡ�\n");
		set("base_unit", "��");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level",275);
		set("wine","/clone/wine/yulujiu");
	}
	setup();
}
