
inherit ROOM;

void create()
{
	set("short", "����ռ�");
	set("long", "����һ������ռ䡣");
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
