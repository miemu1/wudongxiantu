//by ��ʼ�� qsh ednpc tools.
// xiaolu10.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ռ�");
	set("long","����ռ䡣");
	set("exits", ([
		"east" : __DIR__"xiaolu11",
		"south" : __DIR__"xiaojiuguan",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/mitan":2+random(2),
	]));
	setup();
}

