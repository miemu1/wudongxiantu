 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji30",
	"north" : __DIR__"zhongji28",
	"east" : __DIR__"zhongji26",
	"west" : __DIR__"zhongji44",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}