
inherit ROOM;

void create()
{
	set("short", "��ռ��ĺ�");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsi10",
		"south" : __DIR__"dongjie6",
	]));
	set("objects", (["/SJSSS5/GW1/G/guais" : 3,"/SJSSS5/GW1/G/guais1" : 5,   ]));
	setup();
}
