

inherit ROOM;

void create()
{
	set("short", "樱花二街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wuliner17",
		"north" : __DIR__"wuliner19",
	]));
	set("price_build", 1000);
	setup();
}
