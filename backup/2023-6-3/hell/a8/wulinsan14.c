

inherit ROOM;

void create()
{
	set("short", "异空间三号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsan13",
		"west" : __DIR__"wulinsan15",
	]));
	set("objects", (["/SJSSS8/GW1/G/guais" : 3,"/SJSSS8/GW1/G/guais1" : 5,   ]));
	setup();
}
