

inherit ROOM;

void create()
{
	set("short", "��ռ����");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wuliner11",
		"west" : __DIR__"wuliner13",
	]));
	set("objects", (["/SJSSS7/GW1/G/guais" : 3,"/SJSSS7/GW1/G/guais1" : 5,   ]));
	setup();
}
