// Room: /d/fuzhou/ximendajie.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������ţ�������ɭɭ�ġ�
LONG );
	set("exits", ([
		"west"  : __DIR__"ximen",
		"east"  : __DIR__"xidajie",
	//	"north" : __DIR__"xihu",
		//"south" : __DIR__"xichansi",
	]));
	set("objects", ([
		__DIR__"npc/cui": 1,
	]));
set("outdoors", "by");
	setup();
}

