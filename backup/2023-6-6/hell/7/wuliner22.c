

inherit ROOM;

void create()
{
	set("short", "南昼二街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"xijie4",
		"north" : __DIR__"wuliner23",
	]));
	set("price_build", 1000);
	setup();
}
