// by jjyy

inherit ROOM;

void create()
{
	set("short", "������ԭ");
	set("long", "����һƬ�������̵ĵط���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"beijie1",
		"north" : __DIR__"beijie3",
	]));
	set("objects", ([
	]));
	setup();
}