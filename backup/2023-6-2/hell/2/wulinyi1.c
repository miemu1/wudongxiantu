// by jjyy

inherit ROOM;

void create()
{
	set("short", "瀚海一街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"beijie3",
		"east" : __DIR__"wulinyi2",
	]));
	//	set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
