// by jjyy

inherit ROOM;

void create()
{
	set("short", "����һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinsan1",
		"east" : __DIR__"dongjie2",
	]));
	set("objects", ([
		"/d/publicnpc/killplayers" : 5,
	]));
	setup();
}
