
inherit ROOM;

void create()
{
	set("short", "嫺��Ľ�");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsi6",
		"south" : __DIR__"wulinsi8",
	]));
		set("objects", (["/HELL2/GuaiWu5/G/guais" : 10,]));
	setup();
}
