 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji19",
	"north" : __DIR__"gaoji17",
	"east" : __DIR__"gaoji57",
	"west" : __DIR__"gaoji13",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}