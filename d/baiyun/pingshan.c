// Room: /d/fuzhou/pingshan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "���Ƴ���");
	set("long", @LONG
������ؼ����ģ�ŵ��ճ�Ψ���ơ����߾��ǰ��Ƴ��ˡ�
LONG );
	set("exits", ([
		"southdown" : __DIR__"beidajie",
	]));
	set("outdoors", "by");
	setup();
}

