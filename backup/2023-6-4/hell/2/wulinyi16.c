// by jjyy

inherit ROOM;

void create()
{
	set("short", "瀚海一街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"xijie3",
		"north" : __DIR__"wulinyi17",
	]));
	//	set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
