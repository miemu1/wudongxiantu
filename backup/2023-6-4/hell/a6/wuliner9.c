

inherit ROOM;

void create()
{
	set("short", "异空间二号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wuliner8",
		"south" : __DIR__"wuliner10",
	]));
	set("objects", (["/SJSSS6/GW1/G/guais" : 3,"/SJSSS6/GW1/G/guais1" : 5,   ]));
	setup();
}
