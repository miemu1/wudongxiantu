// by jjyy

inherit ROOM;

void create()
{
	set("short", "北空间五号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"beijie4",
		"east" : __DIR__"wulinsan1",
		"west" : __DIR__"wulinsan36",
		"north" : __DIR__"beijie6",
	]));
	set("objects", (["/SJSSS7/GW1/G/guais" : 3,"/SJSSS7/GW1/G/guais1" : 5,
	]));
	setup();
}