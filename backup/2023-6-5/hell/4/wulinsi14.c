
inherit ROOM;

void create()
{
	set("short", "东阳四街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinsi15",
		"north" : __DIR__"wulinsi13",
	]));
	set("price_build", 1000);
	setup();
}
