// by jjyy

inherit ROOM;

void create()
{
	set("short", "���ֶ���");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"xijie1",
		"west" : __DIR__"xijie3",
	]));
	set("objects", ([
		"/d/publicnpc/killplayer" : 1,
		"/d/publicnpc/killplayers" : 1,
		"/d/publicnpc/killplayerss" : 1,
	]));
	setup();
}