

inherit ROOM;

void create()
{
	set("short", "��ռ����");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wuliner26",
		"east" : __DIR__"wuliner28",
	]));
	set("objects", (["/SJSSS7/GW1/G/guais" : 3,"/SJSSS7/GW1/G/guais1" : 5,   ]));
	setup();
}
