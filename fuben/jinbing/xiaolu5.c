//by 秦始皇 qsh ednpc tools.
// xiaolu5.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","关外小路");
	set("long","这里是关外小路，管理员尚未设定本地详细描述。");
	set("exits", ([
		"west" : __DIR__"xiaolu8",
		"south" : __DIR__"xiaolu6",
		"north" : __DIR__"xiaojiuguan",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/mitan":2+random(2),
	]));
	setup();
}

