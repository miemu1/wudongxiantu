// dangui.c

#include "herb.h"

void create()
{
	set_name(HIY "�Һ�" NOR, ({ "tao zhong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���ǿ�����Ϊ���ӵ��Һˣ���˵�ڱ�����ջ�Ե������������ֲ�����ӡ�\n");
		set("base_unit", "ö");
		set("base_value", 10000);
		set("base_weight", 70);
		//set("level",400);
		//set("wine","/clone/wine/monkey");
	}
	setup();
}
