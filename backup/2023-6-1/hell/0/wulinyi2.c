// by jjyy

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", "����һƬ�������̵ĵط���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinyi1",
		"east" : __DIR__"wulinyi3",
	]));
	//set("objects", ([
	setup();
}
