 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji42",
	"north" : __DIR__"zhongji44",
	"east" : __DIR__"zhongji30",
	"west" : __DIR__"zhongji48",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}