// by jjyy

inherit ROOM;

void create()
{
	set("short", "���ռ�һ��");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"guangchang",
		"east" : __DIR__"dongjie2",
	]));
	set("objects", (["/SJSSS6/GW1/G/guais" : 3,"/SJSSS6/GW1/G/guais1" : 5,
	]));
	setup();
}
