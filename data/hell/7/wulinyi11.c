// by jjyy

inherit ROOM;

void create()
{
	set("short", "����һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"nanjie3",
		"west" : __DIR__"wulinyi12",
	]));
		set("objects", ([
		"/d/publicnpc/killplayer" : 1,
		"/d/publicnpc/killplayers" : 1,
		"/d/publicnpc/killplayerss" : 1,
	]));
	setup();
}