// dangui.c

#include "herb.h"

void create()
{
	set_name(RED "����" NOR, ({ "tao zi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
	//	set("long", "��˵���ӷǳ�ϲ��������֮����ʹ�����˵ĳЩ���ӻ��ͶԵ�����Ժ������Ϊ�ر���\n");
		set("long","����һö���ʵ����ӡ�"ZJURL("cmds:use tao zi-b")ZJSIZE(22)"����"NOR"֮��������100��������Ϊ��ע�������������ã����ܳ���������������ޡ�\n");
		set("base_unit", "ö");
		set("base_value", 10000);
		set("base_weight", 70);
		set("level",400);
		set("only_do_effect", 1);
		//set("wine","/clone/wine/monkey");
	}
	setup();
}
int do_effect(object me)
{
	

    if (me->query("max_neili") > me->query_neili_limit())
      		return notify_fail("���Ѿ�����ʹ������������������Ϊ�ˡ�\n"); 
 
	me->add("max_neili", 100);

    message_vision(me->query("name")+"����һö"RED"����"NOR"���پ�����������"NOR"\n",me);
	add_amount(-1);
	return 1;
}