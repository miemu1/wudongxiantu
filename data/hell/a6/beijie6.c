// by jjyy

inherit ROOM;

void create()
{
	set("short", "北空间五号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"beijie5",
		"east" : __DIR__"wulinsi1",
		//"west" : __DIR__"wulinsi56",
		//"north" : __DIR__"beijie7",
	]));
	set("objects", (["/SJSSS6/GW1/G/guais" : 3,"/SJSSS6/GW1/G/guais1" : 5,
	]));
	setup();
}