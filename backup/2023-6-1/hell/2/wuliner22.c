

inherit ROOM;

void create()
{
	set("short", "嫺�����");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"xijie4",
		"north" : __DIR__"wuliner23",
	]));
		set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
