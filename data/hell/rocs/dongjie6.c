
inherit ROOM;

void create()
{
	set("short", "虚拟空间");
	set("long", "这是一个虚拟空间。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"dongjie5",
		"north" : __DIR__"wulinsi11",
		//"east" : __DIR__"dongjie7",
		"south" : __DIR__"wulinsi12",
	]));
	set("objects", (["/adm/npc/renou1" : 1,
	]));
	setup();
}
