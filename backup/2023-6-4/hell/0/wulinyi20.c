// by jjyy

inherit ROOM;

void create()
{
	set("short", "荒原");
	set("long", "这是一片荒无人烟的地方。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinyi19",
		"east" : __DIR__"beijie3",
	]));
	//set("objects", ([
	setup();
}
