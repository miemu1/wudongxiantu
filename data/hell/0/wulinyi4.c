// by jjyy

inherit ROOM;

void create()
{
	set("short", "荒原");
	set("long", "这是一片荒无人烟的地方。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinyi3",
		"south" : __DIR__"wulinyi5",
	]));
	//set("objects", ([
	setup();
}
