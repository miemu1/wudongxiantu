 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji20",
	"north" : __DIR__"gaoji18",
	"east" : __DIR__"gaoji58",
	"west" : __DIR__"gaoji12",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}