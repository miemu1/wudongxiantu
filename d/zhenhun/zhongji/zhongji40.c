 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji39",
	"north" : __DIR__"zhongji41",
	"east" : __DIR__"zhongji33",
	"west" : __DIR__"zhongji51",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}