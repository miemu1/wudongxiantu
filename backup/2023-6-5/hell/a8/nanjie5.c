
inherit ROOM;

void create()
{
	set("short", "南空间五号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie4",
		"south" : __DIR__"nanjie6",
		"east" : __DIR__"wulinsan18",
		"west" : __DIR__"wulinsan19",
	]));
	set("objects", (["/SJSSS8/GW1/G/guais" : 3,"/SJSSS8/GW1/G/guais1" : 5,
	]));
	setup();
}