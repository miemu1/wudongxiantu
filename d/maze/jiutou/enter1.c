// Room: /city/beimen.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "日寇侵华");
	set("long", @LONG
这是日寇侵华战场，勇士们镇压日寇，犯我中华者，虽远必诛。
LONG );
    
	set("exits", ([
		"northeast" : "/d/city/guangchang",
		

	]));

	set("outdoors", "city");
	setup();
}

