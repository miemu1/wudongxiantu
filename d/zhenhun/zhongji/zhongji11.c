 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji10",
	"north" : __DIR__"zhongji12",
	"east" : __DIR__"zhongji20",
	"west" : __DIR__"zhongji23",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	"/d/zhenhun/npc/qiutu2b" : 1 + random(3),
	]));
	setup();
}