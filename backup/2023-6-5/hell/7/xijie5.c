// by jjyy

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"xijie4",
		"north" : __DIR__"wulinsan28",
		"south" : __DIR__"wulinsan27",
	]));
	set("objects", ([
		"/d/publicnpc/killplayer" : 1,
		"/d/publicnpc/killplayers" : 1,
		"/d/publicnpc/killplayerss" : 1,
	]));
	setup();
}