
inherit ROOM;

void create()
{
	set("short", "��ռ�����");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsan35",
		"west" : __DIR__"wulinsan33",
	]));
	set("objects", (["/SJSSS8/GW1/G/guais" : 3,"/SJSSS8/GW1/G/guais1" : 5,   ]));
	setup();
}
