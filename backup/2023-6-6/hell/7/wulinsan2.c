

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinsan1",
		"east" : __DIR__"wulinsan3",
	]));
	set("objects", ([
		"/d/publicnpc/killplayers" : 5,
	]));
	setup();
}
