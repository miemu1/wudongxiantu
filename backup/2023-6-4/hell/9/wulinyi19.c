// by jjyy

inherit ROOM;

void create()
{
	set("short", "樱花一街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinyi18",
		"east" : __DIR__"wulinyi20",
	]));
	//set("price_build", 1000);
	setup();
}
