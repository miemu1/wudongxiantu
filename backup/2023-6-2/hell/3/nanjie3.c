// by jjyy

inherit ROOM;

void create()
{
	set("short", "�Ͻ�����");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie2",
		"south" : __DIR__"nanjie4",
		"east" : __DIR__"wulinyi10",
		"west" : __DIR__"wulinyi11",
	]));
	set("objects", ([
		"/HELL3/GuaiWu5/G/guais1" : 4,"/HELL3/GuaiWu5/G/guais" : 1,
	]));
	setup();
}