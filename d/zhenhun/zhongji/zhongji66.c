 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji65",
	"north" : __DIR__"zhongji67",
	"east" : __DIR__"zhongji79",
	"west" : __DIR__"zhongji61",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}