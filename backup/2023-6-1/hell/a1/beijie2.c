// by jjyy

inherit ROOM;

void create()
{
	set("short", "北空间二号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"beijie1",
		"north" : __DIR__"beijie3",
	]));
	set("objects", (["/SJSSS1/GW1/G/guais" : 5,"/SJSSS1/GW1/G/guais1" : 5,
	]));
	setup();
}