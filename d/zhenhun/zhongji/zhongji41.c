 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji40",
	"north" : __DIR__"zhongji42",
	"east" : __DIR__"zhongji32",
	"west" : __DIR__"zhongji50",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}