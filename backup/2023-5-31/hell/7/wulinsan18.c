

inherit ROOM;

void create()
{
	set("short", "南昼三街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsan17",
		"west" : __DIR__"nanjie5",
	]));
	set("price_build", 1000);
	setup();
}
