 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji41",
	"north" : __DIR__"gaoji43",
	"east" : __DIR__"gaoji31",
	"west" : __DIR__"gaoji49",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}