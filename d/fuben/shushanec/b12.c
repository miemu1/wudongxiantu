// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIW"天倾"NOR);
	set("long", @LONG
蜀山从古至今各代掌门的剑灵守护者此地。
LONG
	);
			set("no_fly",1);
	set("exits", ([
		"east" : __DIR__"b10",
	]));
	set("objects", ([
   __DIR__"npc/a4":3,
	]));
	setup();
}
#include "/d/fuben/room_fb.h"