// by jjyy

inherit ROOM;

void create()
{
	set("short", "�Ͻֶ���");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie1",
		"south" : __DIR__"nanjie3",
	]));
	set("objects", ([
		"/HELL6/GuaiWu2/G/guais" : 3,
	]));
	setup();
}