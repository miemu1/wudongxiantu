 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji38",
	"north" : __DIR__"gaoji40",
	"east" : __DIR__"gaoji34",
	"west" : __DIR__"gaoji52",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}