// by jjyy

inherit ROOM;

void create()
{
	set("short", "嫺�һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinyi12",
		"north" : __DIR__"wulinyi14",
	]));
	//	set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
