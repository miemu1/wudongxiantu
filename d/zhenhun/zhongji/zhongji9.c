 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji7",
	"north" : __DIR__"zhongji21",
	"east" : __DIR__"zhongji61",
	"west" : __DIR__"zhongji5",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}