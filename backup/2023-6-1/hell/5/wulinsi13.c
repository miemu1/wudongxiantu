
inherit ROOM;

void create()
{
	set("short", "西月四街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinsi14",
		"north" : __DIR__"wulinsi12",
	]));
	set("price_build", 1000);
	setup();
}
