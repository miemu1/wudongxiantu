// by jjyy

inherit ROOM;

void create()
{
	set("short", "�ϲ���ԭ");
	set("long", "����һƬ�������̵ĵط���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"nanjie2",
	]));
	set("objects", ([
	]));
	setup();
}