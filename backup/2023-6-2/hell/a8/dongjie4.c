// by jjyy

inherit ROOM;

void create()
{
	set("short", "���ռ��ĺ�");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"dongjie3",
		"east" : __DIR__"dongjie5",
		"north" : __DIR__"wuliner7",
		"south" : __DIR__"wuliner8",
	]));
	set("objects", (["/SJSSS8/GW1/G/guais" : 3,"/SJSSS8/GW1/G/guais1" : 5,
	]));
	setup();
}
