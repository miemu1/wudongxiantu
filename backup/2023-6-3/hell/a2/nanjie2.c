// by jjyy

inherit ROOM;

void create()
{
	set("short", "南空间二号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie1",
		"south" : __DIR__"nanjie3",
	]));
	set("objects", (["/SJSSS2/GW1/G/guais" : 3,"/SJSSS2/GW1/G/guais1" : 5,
	]));
	setup();
}