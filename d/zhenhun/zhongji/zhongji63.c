 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"north" : __DIR__"zhongji62",
	"east" : __DIR__"zhongji64",
	"west" : __DIR__"zhongji2",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}