
inherit ROOM;

void create()
{
	set("short", "����ռ�");
	set("long", "����һ������ռ䡣");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie5",
		"east" : __DIR__"wulinsi22",
		//"west" : __DIR__"wulinsan19",
	]));
	set("objects", (["/adm/npc/renou2" : 1,
	]));
	setup();
}