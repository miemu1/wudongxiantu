// by jjyy

inherit ROOM;

void create()
{
	set("short", "���ռ��ĺ�");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"beijie3",
		"north" : __DIR__"beijie5",
		"east" : __DIR__"wuliner1",
		"west" : __DIR__"wuliner28",
	]));
	set("objects", (["/SJSSS5/GW1/G/guais" : 3,"/SJSSS5/GW1/G/guais1" : 5,
	]));
	setup();
}