
inherit ROOM;

void create()
{
	set("short", "新手四街");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinsi15",
		"north" : __DIR__"wulinsi13",
	]));
	set("objects", (["/HELL1a/GuaiWu5/G/guais" : 5,"/HELL1a/GuaiWu1/G/guais" : 5,
	setup();
}
