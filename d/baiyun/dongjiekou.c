// Room: /d/fuzhou/dongjiekou.c
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����æ�Ľֵ��ϣ����ﲻ�ɵ���һ˿���ˡ�
LONG );

	set("exits", ([
		"south"   : __DIR__"nandajie",
		"north"   : __DIR__"beidajie",
	
	]));
	set("objects", ([
		//"/d/city/npc/liumangtou" : 1,
		//"/d/city/npc/liumang" : 3,
	]));
set("outdoors", "by");
	setup();
}

