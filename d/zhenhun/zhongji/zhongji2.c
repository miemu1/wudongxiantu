 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"north" : __DIR__"zhongji7",
	"east" : __DIR__"zhongji63",
	"west" : __DIR__"zhongji1",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}