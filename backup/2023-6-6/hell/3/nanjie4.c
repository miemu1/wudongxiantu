// by jjyy

inherit ROOM;

void create()
{
	set("short", "�Ͻ��ĺ�");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie3",
		"south" : __DIR__"nanjie5",
		"east" : __DIR__"wuliner14",
		"west" : __DIR__"wuliner15",
	]));
	set("objects", ([
		"/HELL3/GuaiWu5/G/guais1" : 4,"/HELL3/GuaiWu5/G/guais" : 1,
	]));
	setup();
}