//by ��ʼ�� qsh ednpc tools.
// xiaolu13.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ռ�");
	set("long","����ռ䡣");
	set("exits", ([
		"south" : __DIR__"xiaolu14",
		"north" : __DIR__"xiaolu12",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/mitan":2+random(2),
	]));
	setup();
}

