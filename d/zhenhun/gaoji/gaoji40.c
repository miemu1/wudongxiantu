 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji39",
	"north" : __DIR__"gaoji41",
	"east" : __DIR__"gaoji33",
	"west" : __DIR__"gaoji51",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}