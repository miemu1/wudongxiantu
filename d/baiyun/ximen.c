// Room: /d/fuzhou/ximen.c
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������ɭ�ĸо���ϸϸƷζ��ʹ��������ʮ�ֹ��졣
LONG );
	set("exits", ([
		"east" : __DIR__"ximendajie",
		"south" : __DIR__"fzroad11",
	]));
	set("outdoors", "by");
	setup();
}

