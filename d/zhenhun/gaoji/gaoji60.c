 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji61",
	"north" : __DIR__"gaoji59",
	"east" : __DIR__"gaoji67",
	"west" : __DIR__"gaoji21",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}