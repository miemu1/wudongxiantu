 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji61",
	"north" : __DIR__"zhongji59",
	"east" : __DIR__"zhongji67",
	"west" : __DIR__"zhongji21",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}