

inherit ROOM;

void create()
{
	set("short", "嫺�����");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wuliner15",
		"west" : __DIR__"wuliner17",
	]));
		set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
