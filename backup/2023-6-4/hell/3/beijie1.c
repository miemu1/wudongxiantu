// by jjyy

inherit ROOM;

void create()
{
	set("short", "北街一号");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wuliner1",
		"north" : __DIR__"beijie2",
	]));
	set("objects", (["/HELL3/GuaiWu5/G/guais1" : 5,"/HELL3/GuaiWu5/G/guais" : 1,]));
	setup();
}
