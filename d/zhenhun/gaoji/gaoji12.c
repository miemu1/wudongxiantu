 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji11",
	"north" : __DIR__"gaoji13",
	"east" : __DIR__"gaoji19",
	"west" : __DIR__"gaoji24",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}