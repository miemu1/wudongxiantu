
inherit ROOM;

void create()
{
	set("short", "���ռ����");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"dongjie5",
		"north" : __DIR__"wulinsi11",
		//"east" : __DIR__"dongjie7",
		"south" : __DIR__"wulinsi12",
	]));
	set("objects", (["/SJSSS5/GW1/G/guais" : 3,"/SJSSS5/GW1/G/guais1" : 5,
	]));
	setup();
}
