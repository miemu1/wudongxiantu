 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji12",
	"north" : __DIR__"zhongji14",
	"east" : __DIR__"zhongji18",
	"west" : __DIR__"zhongji25",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}