// by jjyy

inherit ROOM;

void create()
{
	set("short", "阎罗殿");
	set("long", "这里是阎罗殿，地府冥君主宰的地方。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"beijie1",
		"south" : __DIR__"nanjie1",
		"west" : __DIR__"xijie1",
		"east" : __DIR__"dongjie1",
	]));
	set("objects", ([
		"/d/publicnpc/killplayersss" : 1,
	]));
	setup();
}

