 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji35",
	"north" : __DIR__"zhongji33",
	"east" : __DIR__"zhongji8",
	"west" : __DIR__"zhongji39",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}