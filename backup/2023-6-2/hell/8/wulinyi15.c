// by jjyy

inherit ROOM;

void create()
{
	set("short", "��ʥһ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinyi14",
		"north" : __DIR__"xijie3",
	]));
	//set("price_build", 1000);
	setup();
}
