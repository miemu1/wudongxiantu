

inherit ROOM;

void create()
{
	set("short", "东阳三街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"beijie5",
		"west" : __DIR__"wulinsan35",
	]));
	set("price_build", 1000);
	setup();
}
