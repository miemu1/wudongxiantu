//by ��ʼ�� qsh ednpc tools.
// shishi.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"ʯ��"NOR);
	set("long","������ʯ�ң�����Ա��δ�趨������ϸ������");
	set("exits", ([
		"north" : __DIR__"huangling2",
	]));
	set("fuben2", 1);
	set("objects", ([
			__DIR__"npc/lihun":5,
	]));
	setup();
}

