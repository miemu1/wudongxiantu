
inherit ROOM;

void create()
{
	set("short", "�����Ľ�");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsi17",
		"west" : __DIR__"wulinsi19",
	]));
	set("objects", (["/HELL1/GuaiWu5/G/guais" : 10,"/HELL1/GuaiWu1/G/guais" : 5,]));
	setup();
}
