

inherit ROOM;

void create()
{
	set("short", "��ʥ����");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsan13",
		"west" : __DIR__"wulinsan15",
	]));
	set("price_build", 1000);
	setup();
}
