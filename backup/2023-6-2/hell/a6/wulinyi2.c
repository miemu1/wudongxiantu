// by jjyy

inherit ROOM;

void create()
{
	set("short", "异空间一号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinyi1",
		"east" : __DIR__"wulinyi3",
	]));
	set("objects", (["/SJSSS6/GW1/G/guais" : 3,"/SJSSS6/GW1/G/guais1" : 5,]));
	setup();
}
