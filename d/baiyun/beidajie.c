// Room: /d/fuzhou/beidajie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ����⡣
LONG );
	set("exits", ([
		"south"   : __DIR__"dongjiekou",
		"northup" : __DIR__"pingshan",
	]));
	set("outdoors", "by");
	setup();
}

