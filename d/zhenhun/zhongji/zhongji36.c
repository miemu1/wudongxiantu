 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"north" : __DIR__"zhongji35",
	"east" : __DIR__"zhongji3",
	"west" : __DIR__"zhongji37",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}