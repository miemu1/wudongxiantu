// by jjyy

inherit ROOM;

void create()
{
	set("short", "嫺�һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinyi1",
		"east" : __DIR__"wulinyi3",
	]));
	//	set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
