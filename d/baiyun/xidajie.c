// Room: /d/fuzhou/xidajie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������������ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ�,���ࡣ
LONG );

	set("exits", ([
		//"southup" : __DIR__"wushan",
		//"north"   : __DIR__"biaoju",
		"east"    : __DIR__"yamen",
		"west"    : __DIR__"ximendajie",
	]));
set("outdoors", "by");
	setup();
}

