
inherit ROOM;

void create()
{
	set("short", "�Ͽռ����");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie4",
		"south" : __DIR__"nanjie6",
		"east" : __DIR__"wulinsan18",
		"west" : __DIR__"wulinsan19",
	]));
	set("objects", (["/SJSSS5/GW1/G/guais" : 3,"/SJSSS5/GW1/G/guais1" : 5,
	]));
	setup();
}