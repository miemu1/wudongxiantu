

inherit ROOM;

void create()
{
	set("short", "虚拟空间");
	set("long", "这是一个虚拟空间。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wuliner22",
		"north" : __DIR__"wuliner24",
	]));
	set("objects", ([
	setup();
}
