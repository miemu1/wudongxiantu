// by jjyy

inherit ROOM;

void create()
{
	set("short", "西街三号");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"xijie2",
		"west" : __DIR__"xijie4",
		"south" : __DIR__"wulinyi15",
		"north" : __DIR__"wulinyi16",
	]));
	set("objects", (["/HELL1/GuaiWu5/G/guais" : 10,"/HELL1/GuaiWu1/G/guais" : 5,]));
	setup();
}