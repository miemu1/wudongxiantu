

inherit ROOM;

void create()
{
	set("short", "��ʥ����");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : "/data/home/q/qiaojia30_1/hell/sc",
		"west" : __DIR__"beijie5",
		"east" : __DIR__"wulinsan2",
	]));
	set("price_build", 1000);
	setup();
}
