 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji36",
	"north" : __DIR__"zhongji34",
	"east" : __DIR__"zhongji6",
	"west" : __DIR__"zhongji38",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}