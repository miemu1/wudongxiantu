// by jjyy

inherit ROOM;

void create()
{
	set("short", "���ռ����");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"xijie1",
		"west" : __DIR__"xijie3",
	]));
	set("objects", (["/SJSSS7/GW1/G/guais" : 3,"/SJSSS7/GW1/G/guais1" : 5,
	]));
	setup();
}