
inherit ROOM;

void create()
{
	set("short", "虚拟空间");
	set("long", "这是一个虚拟空间。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinsi3",
		"east" : __DIR__"wulinsi5",
	]));
	set("objects", ([
	setup();
}
