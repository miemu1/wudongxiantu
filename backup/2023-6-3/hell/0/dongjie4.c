// by jjyy

inherit ROOM;

void create()
{
	set("short", "������ԭ");
	set("long", "����һƬ�������̵ĵط���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"dongjie3",
		"east" : __DIR__"dongjie5",
		"north" : __DIR__"wuliner7",
		"south" : __DIR__"wuliner8",
	]));
	set("objects", ([
	]));
	setup();
}
