 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji58",
	"north" : __DIR__"zhongji56",
	"east" : __DIR__"zhongji70",
	"west" : __DIR__"zhongji18",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}