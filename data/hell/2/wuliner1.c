// by jjyy

inherit ROOM;

void create()
{
	set("short", "嫺�����");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"beijie4",
		"east" : __DIR__"wuliner2",
	]));

		set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
