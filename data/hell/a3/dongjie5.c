// by jjyy

inherit ROOM;

void create()
{
	set("short", "东空间五号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"dongjie6",
		"west" : __DIR__"dongjie4",
		"north" : __DIR__"wulinsan9",
		"south" : __DIR__"wulinsan10",
	]));
	set("objects", (["/SJSSS3/GW1/G/guais" : 3,"/SJSSS3/GW1/G/guais1" : 5,
	]));
	setup();
}
