//by ��ʼ�� qsh ednpc tools.
// xiaojiuguan.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ռ�");
	set("long","����ռ䡣");
	set("exits", ([
		"north" : __DIR__"xiaolu10",
		"south" : __DIR__"xiaolu5",
		"west" : __DIR__"xiaolu2",
	]));
	set("fuben2", 1);
	set("objects", ([
			__DIR__"npc/gaoshou":1,
		//"fuben/wuguan/obj/baoxiang":1,	
	]));
	setup();
}

