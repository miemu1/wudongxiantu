// by jjyy

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", "����һƬ�������̵ĵط���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"dongjie3",
		"south" : __DIR__"wulinyi7",
	]));
	//set("objects", ([
	setup();
}
