// by jjyy

inherit ROOM;

void create()
{
	set("short", "ӣ��һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"xijie3",
		"north" : __DIR__"wulinyi17",
	]));
	//set("price_build", 1000);
	setup();
}
