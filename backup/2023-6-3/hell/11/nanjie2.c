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
		"/Aboss2/GW1/G/guais" : 5,
	]));
	setup();
}