// Room: /data/hell/9/xidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"beijie2",
	]));
	set("objects", ([
		"/HELL9/GuaiWu1/G/guais" : 5,
	]));
	setup();
}
