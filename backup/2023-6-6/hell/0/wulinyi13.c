// by jjyy

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", "����һƬ�������̵ĵط���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinyi12",
		"north" : __DIR__"wulinyi14",
	]));
	//set("objects", ([
	setup();
}
