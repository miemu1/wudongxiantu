

inherit ROOM;

void create()
{
	set("short", "��ʥ����");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wuliner27",
		"east" : __DIR__"beijie4",
	]));
	set("price_build", 1000);
	setup();
}
