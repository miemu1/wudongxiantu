 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji13",
	"north" : __DIR__"zhongji15",
	"east" : __DIR__"zhongji17",
	"west" : __DIR__"zhongji26",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}