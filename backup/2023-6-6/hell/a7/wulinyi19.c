// by jjyy

inherit ROOM;

void create()
{
	set("short", "��ռ�һ��");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinyi18",
		"east" : __DIR__"wulinyi20",
	]));
	set("objects", (["/SJSSS7/GW1/G/guais" : 3,"/SJSSS7/GW1/G/guais1" : 5,]));
	setup();
}
