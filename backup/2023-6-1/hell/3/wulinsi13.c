
inherit ROOM;

void create()
{
	set("short", " 风云四街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinsi14",
		"north" : __DIR__"wulinsi12",
	]));
	set("objects", (["/HELL3/GuaiWu5/G/guais1" : 4,"/HELL3/GuaiWu5/G/guais" : 1,]));
	setup();
}
