

inherit ROOM;

void create()
{
	set("short", "东阳三街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsan13",
		"west" : __DIR__"wulinsan15",
	]));
	set("price_build", 1000);
	setup();
}
