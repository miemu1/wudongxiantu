
inherit ROOM;

void create()
{
	set("short", "��ռ��ĺ�");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinsi5",
		"south" : __DIR__"wulinsi7",
	]));
	set("objects", (["/SJSSS6/GW1/G/guais" : 3,"/SJSSS6/GW1/G/guais1" : 5,   ]));
	setup();
}
