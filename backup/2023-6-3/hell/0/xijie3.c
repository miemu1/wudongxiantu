// by jjyy

inherit ROOM;

void create()
{
	set("short", "������ԭ");
	set("long", "����һƬ�������̵ĵط���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"xijie2",
		"west" : __DIR__"xijie4",
		"south" : __DIR__"wulinyi15",
		"north" : __DIR__"wulinyi16",
	]));
	set("objects", ([
	]));
	setup();
}