// by jjyy

inherit ROOM;

void create()
{
	set("short", "������ԭ");
	set("long", "����һƬ�������̵ĵط���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"dongjie2",
		"east" : __DIR__"dongjie4",
		"north" : __DIR__"wulinyi5",
		"south" : __DIR__"wulinyi6",
	]));
	set("objects", ([
	]));
	setup();
}
