
inherit ROOM;

void create()
{
	set("short", "��ռ��ĺ�");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinsi13",
		"north" : __DIR__"dongjie6",
	]));
	set("objects", (["/SJSSS1/GW1/G/guais" : 5,"/SJSSS1/GW1/G/guais1" : 5,   ]));
	setup();
}
