// by jjyy

inherit ROOM;

void create()
{
	set("short", "虚拟空间");
	set("long", "这是一个虚拟空间。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"beijie2",
	]));
	set("objects", (["/adm/npc/renou" : 1,
	]));
	setup();
}
