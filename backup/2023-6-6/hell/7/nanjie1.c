// by jjyy

inherit ROOM;

void create()
{
	set("short", "�Ͻ�һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinyi1",
		"south" : __DIR__"nanjie2",
	]));
	set("objects", ([
		"/d/publicnpc/killplayerss" : 4,
	]));
	setup();
}