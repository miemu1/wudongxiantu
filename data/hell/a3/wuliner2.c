// by jjyy

inherit ROOM;

void create()
{
	set("short", "异空间二号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wuliner1",
		"east" : __DIR__"wuliner3",
	]));
	set("objects", (["/SJSSS3/GW1/G/guais" : 3,"/SJSSS3/GW1/G/guais1" : 5,   ]));
	setup();
}
