// by jjyy

inherit ROOM;

void create()
{
	set("short", "���ռ����");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"beijie1",
		"north" : __DIR__"beijie3",
	]));
	set("objects", (["/SJSSS2/GW1/G/guais" : 3,"/SJSSS2/GW1/G/guais1" : 5,
	]));
	setup();
}