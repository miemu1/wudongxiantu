 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"north" : __DIR__"zhongji38",
	"east" : __DIR__"zhongji36",
	"west" : __DIR__"zhongji54",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}