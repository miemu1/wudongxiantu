// by jjyy

inherit ROOM;

void create()
{
	set("short", "东部荒原");
	set("long", "这是一片荒无人烟的地方。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"guangchang",
		"east" : __DIR__"dongjie2",
	]));
	set("objects", ([
	]));
	setup();
}
