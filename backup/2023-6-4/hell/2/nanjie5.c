
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
	set("objects", ([		"/HELL2/GuaiWu5/G/guais" : 10,
	]));
	setup();
}