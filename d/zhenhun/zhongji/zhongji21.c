 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji9",
	"north" : __DIR__"zhongji20",
	"east" : __DIR__"zhongji60",
	"west" : __DIR__"zhongji10",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}