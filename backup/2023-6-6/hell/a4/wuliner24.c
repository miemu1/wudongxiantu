

inherit ROOM;

void create()
{
	set("short", "��ռ����");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wuliner23",
		"north" : __DIR__"wuliner25",
	]));
	set("objects", (["/SJSSS4/GW1/G/guais" : 3,"/SJSSS4/GW1/G/guais1" : 5,   ]));
	setup();
}
