// by jjyy

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", "����һƬ�������̵ĵط���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinyi16",
		"north" : __DIR__"wulinyi18",
	]));
	//set("objects", ([
	setup();
}
