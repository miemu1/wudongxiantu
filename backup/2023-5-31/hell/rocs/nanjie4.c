// by jjyy

inherit ROOM;

void create()
{
	set("short", "����ռ�");
	set("long", "����һ������ռ䡣");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie3",
		"south" : __DIR__"nanjie5",
		"east" : __DIR__"wuliner14",
		"west" : __DIR__"wuliner15",
	]));
	set("objects", (["/adm/npc/renou2" : 1,
	]));
	setup();
}