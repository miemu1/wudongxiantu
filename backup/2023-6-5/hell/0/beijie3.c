// by jjyy

inherit ROOM;

void create()
{
	set("short", "������ԭ");
	set("long", "����һƬ�������̵ĵط���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"beijie2",
		"north" : __DIR__"beijie4",
		"east" : __DIR__"wulinyi1",
		"west" : __DIR__"wulinyi20",
	]));
	set("objects", ([
	]));
	setup();
}