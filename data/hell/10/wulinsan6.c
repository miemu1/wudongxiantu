

inherit ROOM;

void create()
{
	set("short", "ӣ������");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsan5",
		"south" : __DIR__"wulinsan7",
	]));
	set("price_build", 1000);
	setup();
}
