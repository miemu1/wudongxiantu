// dangui.c

#include "herb.h"

void create()
{
	set_name(HIR "����" NOR, ({ "tao zi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��˵���ӷǳ�ϲ��������֮����ʹ�����˵ĳЩ���ӻ��ͶԵ�����Ժ������Ϊ�ر���\n");
		set("base_unit", "ö");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level",400);
		set("wine","/clone/wine/monkey");
	}
	setup();
}
