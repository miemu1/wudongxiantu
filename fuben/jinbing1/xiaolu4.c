//by ��ʼ�� qsh ednpc tools.
// xiaolu4.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ռ�");
	set("long","����ռ䡣");
	set("exits", ([
		"east" : __DIR__"xiaolu3",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/mitan":random(2),
	]));
	setup();
}

