 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"north" : __DIR__"zhongji35",
	"east" : __DIR__"zhongji3",
	"west" : __DIR__"zhongji37",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}