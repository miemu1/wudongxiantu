// by jjyy

inherit ROOM;

void create()
{
	set("short", "东阳二街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wuliner4",
		"south" : __DIR__"wuliner6",
	]));
	set("price_build", 1000);
	setup();
}
