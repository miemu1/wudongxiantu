 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji21",
	"north" : __DIR__"zhongji19",
	"east" : __DIR__"zhongji59",
	"west" : __DIR__"zhongji11",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}