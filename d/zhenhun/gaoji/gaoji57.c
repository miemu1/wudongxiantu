 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji58",
	"north" : __DIR__"gaoji56",
	"east" : __DIR__"gaoji70",
	"west" : __DIR__"gaoji18",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}