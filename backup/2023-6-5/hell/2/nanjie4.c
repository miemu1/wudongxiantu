// by jjyy

inherit ROOM;

void create()
{
	set("short", "�Ͻ��ĺ�");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie3",
		"south" : __DIR__"nanjie5",
		"east" : __DIR__"wuliner14",
		"west" : __DIR__"wuliner15",
	]));
	set("objects", ([		"/HELL2/GuaiWu5/G/guais" : 10,
	]));
	setup();
}