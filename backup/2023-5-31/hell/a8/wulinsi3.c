
inherit ROOM;

void create()
{
	set("short", "异空间四号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinsi2",
		"east" : __DIR__"wulinsi4",
	]));
	set("objects", (["/SJSSS8/GW1/G/guais" : 3,"/SJSSS8/GW1/G/guais1" : 5,   ]));
	setup();
}
