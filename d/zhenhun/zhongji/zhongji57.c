 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji58",
	"north" : __DIR__"zhongji56",
	"east" : __DIR__"zhongji70",
	"west" : __DIR__"zhongji18",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}