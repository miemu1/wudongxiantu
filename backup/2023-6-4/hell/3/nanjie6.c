
inherit ROOM;

void create()
{
	set("short", "�Ͻ�����");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie5",
		"east" : __DIR__"wulinsi22",
		//"west" : __DIR__"wulinsan19",
	]));
	set("objects", ([
		"/HELL3/GuaiWu5/G/guais1" : 4,"/HELL3/GuaiWu5/G/guais" : 1,
	]));
	setup();
}