

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinsan2",
		"east" : __DIR__"wulinsan4",
	]));
	set("objects", ([
		"/d/publicnpc/killplayers" : 5,
	]));
	setup();
}
