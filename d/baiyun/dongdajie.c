// Room: /d/fuzhou/dongdajie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ����š�
LONG );
	set("exits", ([
	
		"east"    : __DIR__"dongxiaojie",
		"west"    : __DIR__"weizhongwei",
	]));

	set("objects", ([
		//"/clone/npc/walker" : 1,
	]));

	set("outdoors", "by");
	setup();
}

