 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji2",
	"north" : __DIR__"gaoji9",
	"east" : __DIR__"gaoji62",
	"west" : __DIR__"gaoji4",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}