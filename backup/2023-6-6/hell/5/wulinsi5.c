

inherit ROOM;

void create()
{
	set("short", "西月四街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinsi4",
		"east" : __DIR__"wulinsi6",
	]));
	set("price_build", 1000);
	setup();
}
