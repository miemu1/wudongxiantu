 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji41",
	"north" : __DIR__"zhongji43",
	"east" : __DIR__"zhongji31",
	"west" : __DIR__"zhongji49",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}