 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji57",
	"north" : __DIR__"gaoji55",
	"east" : __DIR__"gaoji71",
	"west" : __DIR__"gaoji17",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}