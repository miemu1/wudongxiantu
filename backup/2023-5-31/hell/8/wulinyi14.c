// by jjyy

inherit ROOM;

void create()
{
	set("short", "四圣一街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinyi13",
		"north" : __DIR__"wulinyi15",
	]));
	//set("price_build", 1000);
	setup();
}
