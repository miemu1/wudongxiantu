 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji63",
	"north" : __DIR__"zhongji61",
	"east" : __DIR__"zhongji65",
	"west" : __DIR__"zhongji7",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}