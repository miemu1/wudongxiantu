// by jjyy

inherit ROOM;

void create()
{
	set("short", "西街五号");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"xijie4",
		"north" : __DIR__"wulinsan28",
		"south" : __DIR__"wulinsan27",
	]));
	set("objects", ([
		"/HELL4/GuaiWu4/G/guais" : 6,
	]));
	setup();
}