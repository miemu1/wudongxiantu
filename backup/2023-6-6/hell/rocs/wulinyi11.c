// by jjyy

inherit ROOM;

void create()
{
	set("short", "虚拟空间");
	set("long", "这是一个虚拟空间。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"nanjie3",
		"west" : __DIR__"wulinyi12",
	]));
	//set("objects", ([
	setup();
}
