 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"north" : __DIR__"gaoji35",
	"east" : __DIR__"gaoji3",
	"west" : __DIR__"gaoji37",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}