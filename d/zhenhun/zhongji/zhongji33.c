 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji34",
	"north" : __DIR__"zhongji32",
	"east" : __DIR__"zhongji22",
	"west" : __DIR__"zhongji40",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}