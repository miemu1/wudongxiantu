 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji71",
	"east" : __DIR__"zhongji73",
	"west" : __DIR__"zhongji55",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}