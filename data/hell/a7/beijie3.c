// by jjyy

inherit ROOM;

void create()
{
	set("short", "���ռ�����");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"beijie2",
		"north" : __DIR__"beijie4",
		"east" : __DIR__"wulinyi1",
		"west" : __DIR__"wulinyi20",
	]));
	set("objects", (["/SJSSS7/GW1/G/guais" : 3,"/SJSSS7/GW1/G/guais1" : 5,
	]));
	setup();
}