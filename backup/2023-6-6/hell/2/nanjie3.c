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
	set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}