// by jjyy

inherit ROOM;

void create()
{
	set("short", "异空间一号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinyi16",
		"north" : __DIR__"wulinyi18",
	]));
	set("objects", (["/SJSSS3/GW1/G/guais" : 3,"/SJSSS3/GW1/G/guais1" : 5,]));
	setup();
}
