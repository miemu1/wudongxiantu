// by jjyy

inherit ROOM;

void create()
{
	set("short", "����ռ�");
	set("long", "����һ������ռ䡣");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"dongjie1",
		"east" : __DIR__"dongjie3",
	]));
	set("objects", (["/adm/npc/renou1" : 1,
	]));
	setup();
}
