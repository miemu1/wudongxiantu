

inherit ROOM;

void create()
{
	set("short", "��ʥ����");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsan33",
		"south" : __DIR__"wulinsan31",
	]));
	set("price_build", 1000);
	setup();
}
