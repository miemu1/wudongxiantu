// Room: /data/hell/9/xidajie2.c
// YZC 1995/12/04 

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
		"/Aboss1/GW1/G/guais" : 5,
	]));
	setup();
}
