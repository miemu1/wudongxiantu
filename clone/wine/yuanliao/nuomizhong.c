// dangui.c

#include "herb.h"

void create()
{
	set_name(WHT "Ŵ����" NOR, ({ "nuomi zhong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������Ʋ��ϵ����ӡ�\n");
		set("base_unit", "��");
		set("base_value", 2000);
		set("base_weight", 70);
		set("level", 100);
		set("end","/clone/wine/yuanliao/nuomi");
	}
	setup();
}
