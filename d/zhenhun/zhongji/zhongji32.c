 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji33",
	"north" : __DIR__"zhongji31",
	"east" : __DIR__"zhongji23",
	"west" : __DIR__"zhongji41",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}