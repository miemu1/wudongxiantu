
inherit ROOM;

void create()
{
	set("short", "�����Ľ�");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"beijie6",
		"east" : __DIR__"wulinsi2",
	]));
	set("objects", ([
		"/d/publicnpc/killplayerss" : 4,
	]));
	setup();
}
