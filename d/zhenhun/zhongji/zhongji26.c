 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji25",
	"north" : __DIR__"zhongji27",
	"east" : __DIR__"zhongji14",
	"west" : __DIR__"zhongji29",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}