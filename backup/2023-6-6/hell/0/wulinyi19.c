// by jjyy

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", "����һƬ�������̵ĵط���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinyi18",
		"east" : __DIR__"wulinyi20",
	]));
	//set("objects", ([
	setup();
}
