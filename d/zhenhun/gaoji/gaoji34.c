 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
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