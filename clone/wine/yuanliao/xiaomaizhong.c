// dangui.c

#include "herb.h"

void create()
{
	set_name(HIY "С����" NOR, ({ "xiaomai zhong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������Ʋ��ϵ����ӡ�\n");
		set("base_unit", "��");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level", 250);
		set("end","/clone/wine/yuanliao/xiaomai");
	}
	setup();
}
