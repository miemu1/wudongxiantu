

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"east" : "/data/home/p/p25801_1/hell/ylwf",
		"north" : __DIR__"wulinsan6",
		"south" : __DIR__"wulinsan8",
	]));
	set("price_build", 1000);
	setup();
}
