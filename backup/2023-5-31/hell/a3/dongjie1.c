// by jjyy

inherit ROOM;

void create()
{
	set("short", "东空间一号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"guangchang",
		"east" : __DIR__"dongjie2",
	]));
	set("objects", (["/SJSSS3/GW1/G/guais" : 3,"/SJSSS3/GW1/G/guais1" : 5,
	]));
	setup();
}
