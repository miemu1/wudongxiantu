

inherit ROOM;

void create()
{
	set("short", "��ռ�����");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsan12",
		"south" : __DIR__"wulinsan14",
	]));
	set("objects", (["/SJSSS5/GW1/G/guais" : 3,"/SJSSS5/GW1/G/guais1" : 5,   ]));
	setup();
}
