 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji18",
	"north" : __DIR__"zhongji16",
	"east" : __DIR__"zhongji56",
	"west" : __DIR__"zhongji14",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}