 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji33",
	"north" : __DIR__"gaoji31",
	"east" : __DIR__"gaoji23",
	"west" : __DIR__"gaoji41",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}