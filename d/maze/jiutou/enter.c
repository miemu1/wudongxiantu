// Room: /city/beimen.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�޾���Ԩ");
	set("long", @LONG
�����޾���Ԩ����ѹ��������֮����
LONG );
    
	set("exits", ([
		"northeast" : "/d/city/guangchang",
		

	]));

	set("objects", ([
		"/u/dragon" : 2,
	]));
	set("outdoors", "city");
	setup();
}

