 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji51",
	"north" : __DIR__"zhongji49",
	"east" : __DIR__"zhongji41",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}