
inherit ROOM;

void create()
{
	set("short", "东空间五号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"dongjie5",
		"north" : __DIR__"wulinsi11",
		//"east" : __DIR__"dongjie7",
		"south" : __DIR__"wulinsi12",
	]));
	set("objects", (["/SJSSS5/GW1/G/guais" : 3,"/SJSSS5/GW1/G/guais1" : 5,
	]));
	setup();
}
