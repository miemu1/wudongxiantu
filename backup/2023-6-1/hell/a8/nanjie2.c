// by jjyy

inherit ROOM;

void create()
{
	set("short", "�Ͽռ����");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie1",
		"south" : __DIR__"nanjie3",
	]));
	set("objects", (["/SJSSS8/GW1/G/guais" : 3,"/SJSSS8/GW1/G/guais1" : 5,
	]));
	setup();
}