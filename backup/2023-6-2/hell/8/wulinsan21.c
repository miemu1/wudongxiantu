

inherit ROOM;

void create()
{
	set("short", "��ʥ����");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsan20",
		"west" : __DIR__"wulinsan22",
	]));
	set("price_build", 1000);
	setup();
}
