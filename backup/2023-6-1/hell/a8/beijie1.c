// by jjyy

inherit ROOM;

void create()
{
	set("short", "���ռ�һ��");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"beijie2",
	]));
	set("objects", (["/SJSSS8/GW1/G/guais" : 3,"/SJSSS8/GW1/G/guais1" : 5,
	]));
	setup();
}
