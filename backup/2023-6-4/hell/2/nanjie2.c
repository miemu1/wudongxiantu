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
	set("objects", ([		"/HELL2/GuaiWu5/G/guais" : 10,
	]));
	setup();
}