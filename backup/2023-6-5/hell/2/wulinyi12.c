// by jjyy

inherit ROOM;

void create()
{
	set("short", "嫺�һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinyi11",
		"west" : __DIR__"wulinyi13",
	]));
	//	set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
