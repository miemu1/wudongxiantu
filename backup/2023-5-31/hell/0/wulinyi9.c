// by jjyy

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", "����һƬ�������̵ĵط���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinyi8",
		"west" : __DIR__"wulinyi10",
	]));
	//set("objects", ([
	setup();
}
