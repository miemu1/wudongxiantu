

inherit ROOM;

void create()
{
	set("short", "瀚海二街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wuliner26",
		"east" : __DIR__"wuliner28",
	]));
		set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
