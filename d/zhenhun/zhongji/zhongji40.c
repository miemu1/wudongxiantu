 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji39",
	"north" : __DIR__"zhongji41",
	"east" : __DIR__"zhongji33",
	"west" : __DIR__"zhongji51",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}