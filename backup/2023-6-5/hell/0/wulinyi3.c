// by jjyy

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", "����һƬ�������̵ĵط���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinyi2",
		"south" : __DIR__"wulinyi4",
	]));
	//set("objects", ([
	setup();
}
