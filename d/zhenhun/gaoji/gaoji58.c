 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji59",
	"north" : __DIR__"gaoji57",
	"east" : __DIR__"gaoji69",
	"west" : __DIR__"gaoji19",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}