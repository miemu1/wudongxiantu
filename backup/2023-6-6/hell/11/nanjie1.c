// Room: /data/hell/9/nanjie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�Ͻ�һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"nanjie2",
	]));
	set("objects", ([
		"/Aboss2/GW1/G/guais" : 5,
	]));
	setup();
}