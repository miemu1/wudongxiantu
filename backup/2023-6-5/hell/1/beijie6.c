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
	set("objects", (["/HELL1/GuaiWu5/G/guais" : 10,"/HELL1/GuaiWu1/G/guais" : 5,]));
	setup();
}