

inherit ROOM;

void create()
{
	set("short", "异空间三号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsan21",
		"west" : __DIR__"wulinsan23",
	]));
	set("objects", (["/SJSSS4/GW1/G/guais" : 3,"/SJSSS4/GW1/G/guais1" : 5,   ]));
	setup();
}
