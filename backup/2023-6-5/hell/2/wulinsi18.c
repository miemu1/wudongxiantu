
inherit ROOM;

void create()
{
	set("short", "嫺��Ľ�");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsi17",
		"west" : __DIR__"wulinsi19",
	]));
		set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
