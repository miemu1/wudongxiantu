

inherit ROOM;

void create()
{
	set("short", "西月二街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wuliner10",
		"west" : __DIR__"wuliner12",
	]));
	set("price_build", 1000);
	setup();
}
