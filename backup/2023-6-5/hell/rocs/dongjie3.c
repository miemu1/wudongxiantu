// by jjyy

inherit ROOM;

void create()
{
	set("short", "����ռ�");
	set("long", "����һ������ռ䡣");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"dongjie2",
		"east" : __DIR__"dongjie4",
		"north" : __DIR__"wulinyi5",
		"south" : __DIR__"wulinyi6",
	]));
	set("objects", (["/adm/npc/renou1" : 1,
	]));
	setup();
}
