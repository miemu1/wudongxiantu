// by jjyy

inherit ROOM;

void create()
{
	set("short", "北街一号");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"beijie2",
	]));
	set("objects", ([
		"/HELL8/GuaiWu4/G/guais" : 3,
	]));
	setup();
}
