
inherit ROOM;

void create()
{
	set("short", "�����Ľ�");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : "/data/home/q/q3043765268_1/hell/wanxia",
		"east" : __DIR__"wulinsi21",
		"west" : __DIR__"nanjie6",
	]));
	set("price_build", 1000);
	setup();
}
