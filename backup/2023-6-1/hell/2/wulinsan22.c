

inherit ROOM;

void create()
{
	set("short", "嫺�����");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsan21",
		"west" : __DIR__"wulinsan23",
	]));
		set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
