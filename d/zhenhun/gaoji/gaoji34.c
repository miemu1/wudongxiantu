 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji35",
	"north" : __DIR__"gaoji33",
	"east" : __DIR__"gaoji8",
	"west" : __DIR__"gaoji39",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}