
inherit ROOM;

void create()
{
	set("short", "嫺��Ľ�");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinsi5",
		"south" : __DIR__"wulinsi7",
	]));
		set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
