// by jjyy

inherit ROOM;

void create()
{
	set("short", "嫺�һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinyi13",
		"north" : __DIR__"wulinyi15",
	]));
	//	set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
