// dangui.c

#include "herb.h"

void create()
{
	set_name(HIY "������" NOR, ({ "yumi zhong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������Ʋ��ϵ����ӡ�\n");
		set("base_unit", "��");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level", 300);
		set("end","/clone/wine/yuanliao/yumi");
	}
	setup();
}
