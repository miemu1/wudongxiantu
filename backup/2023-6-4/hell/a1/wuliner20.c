

inherit ROOM;

void create()
{
	set("short", "��ռ����");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wuliner19",
		"north" : __DIR__"wuliner21",
	]));
	set("objects", (["/SJSSS1/GW1/G/guais" : 5,"/SJSSS1/GW1/G/guais1" : 5,   ]));
	setup();
}
