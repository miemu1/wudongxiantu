// by jjyy

inherit ROOM;

void create()
{
	set("short", "����ռ�");
	set("long", "����һ������ռ䡣");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"beijie2",
	]));
	set("objects", (["/adm/npc/renou" : 1,
	]));
	setup();
}
