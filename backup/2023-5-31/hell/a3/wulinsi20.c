
inherit ROOM;

void create()
{
	set("short", "��ռ��ĺ�");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsi19",
		"west" : __DIR__"wulinsi21",
	]));
	set("objects", (["/SJSSS3/GW1/G/guais" : 3,"/SJSSS3/GW1/G/guais1" : 5,   ]));
	setup();
}
