
inherit ROOM;

void create()
{
	set("short", "南昼四街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsi7",
		"south" : __DIR__"wulinsi9",
	]));
	set("price_build", 1000);
	setup();
}
