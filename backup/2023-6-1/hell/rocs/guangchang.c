// by jjyy

inherit ROOM;

void create()
{
	set("short", "虚拟空间");
	set("long", "这里是虚拟空间。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"beijie1",
		"south" : __DIR__"nanjie1",
		"west" : __DIR__"xijie1",
		"east" : __DIR__"dongjie1",
	]));
	set("objects", ([
	]));
	setup();
}

