// by jjyy

inherit ROOM;

void create()
{
	set("short", "东阳一街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinyi11",
		"west" : __DIR__"wulinyi13",
	]));
	//set("price_build", 1000);
	setup();
}
