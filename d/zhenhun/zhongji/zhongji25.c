 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji24",
	"north" : __DIR__"zhongji26",
	"east" : __DIR__"zhongji13",
	"west" : __DIR__"zhongji30",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}