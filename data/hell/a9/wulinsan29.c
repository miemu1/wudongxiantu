

inherit ROOM;

void create()
{
	set("short", "��ռ�����");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsan30",
		"south" : __DIR__"wulinsan28",
	]));
	set("objects", (["/SJSSS9/GW1/G/guais" : 3,"/SJSSS9/GW1/G/guais1" : 5,   ]));
	setup();
}
