 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji62",
	"north" : __DIR__"zhongji60",
	"east" : __DIR__"zhongji66",
	"west" : __DIR__"zhongji9",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}