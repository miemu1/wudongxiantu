// by jjyy

inherit ROOM;

void create()
{
	set("short", "�Ͻ����");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie4",
		"south" : __DIR__"nanjie6",
		"east" : __DIR__"wulinsan18",
		"west" : __DIR__"wulinsan19",
	]));
	set("objects", ([
		"/HELL6/GuaiWu2/G/guais" : 3,
	]));
	setup();
}