
inherit ROOM;

void create()
{
	set("short", "南部荒原");
	set("long", "这是一片荒无人烟的地方。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie4",
		"south" : __DIR__"nanjie6",
		"east" : __DIR__"wulinsan18",
		"west" : __DIR__"wulinsan19",
	]));
	set("objects", ([
	]));
	setup();
}