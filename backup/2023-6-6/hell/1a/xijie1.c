

inherit ROOM;

void create()
{
	set("short", "西街一号");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"guangchang",
		"west" : __DIR__"xijie2",
	]));
	set("objects", (["/HELL1a/GuaiWu5/G/guais" : 5,"/HELL1a/GuaiWu1/G/guais" : 5,
	]));
	setup();
}