

inherit ROOM;

void create()
{
	set("short", "南昼三街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"dongjie5",
		"south" : __DIR__"wulinsan11",
	]));
	set("price_build", 1000);
	setup();
}
