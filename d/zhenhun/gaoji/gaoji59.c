 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji60",
	"north" : __DIR__"gaoji58",
	"east" : __DIR__"gaoji68",
	"west" : __DIR__"gaoji20",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}