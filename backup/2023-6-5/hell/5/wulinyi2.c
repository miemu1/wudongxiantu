// by jjyy

inherit ROOM;

void create()
{
	set("short", "西月一街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinyi1",
		"east" : __DIR__"wulinyi3",
	]));
	//set("price_build", 1000);
	setup();
}
