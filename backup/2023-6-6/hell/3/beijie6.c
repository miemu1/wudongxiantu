// by jjyy

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"beijie5",
		"east" : __DIR__"wulinsi1",
		//"west" : __DIR__"wulinsi56",
		//"north" : __DIR__"beijie7",
	]));
	set("objects", ([
		"/HELL3/GuaiWu5/G/guais1" : 4,"/HELL3/GuaiWu5/G/guais" : 1,
	]));
	setup();
}