 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji31",
	"north" : __DIR__"zhongji29",
	"east" : __DIR__"zhongji25",
	"west" : __DIR__"zhongji43",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}