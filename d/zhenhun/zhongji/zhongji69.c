 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji68",
	"north" : __DIR__"zhongji70",
	"east" : __DIR__"zhongji76",
	"west" : __DIR__"zhongji58",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}