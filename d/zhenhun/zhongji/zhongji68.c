 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji67",
	"north" : __DIR__"zhongji69",
	"east" : __DIR__"zhongji77",
	"west" : __DIR__"zhongji59",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}