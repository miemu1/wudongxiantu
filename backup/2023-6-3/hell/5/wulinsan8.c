

inherit ROOM;

void create()
{
	set("short", "西月三街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsan7",
		"south" : __DIR__"wulinsan9",
	]));
	set("price_build", 1000);
	setup();
}
