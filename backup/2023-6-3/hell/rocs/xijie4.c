// by jjyy

inherit ROOM;

void create()
{
	set("short", "����ռ�");
	set("long", "����һ������ռ䡣");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"xijie3",
		"west" : __DIR__"xijie5",
		"north" : __DIR__"wuliner22",
		"south" : __DIR__"wuliner21",
	]));
	set("objects", (["/adm/npc/renou3" : 1,
	]));
	setup();
}