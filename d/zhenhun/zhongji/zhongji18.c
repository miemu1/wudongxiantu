 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji19",
	"north" : __DIR__"zhongji17",
	"east" : __DIR__"zhongji57",
	"west" : __DIR__"zhongji13",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}