 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji38",
	"north" : __DIR__"zhongji40",
	"east" : __DIR__"zhongji34",
	"west" : __DIR__"zhongji52",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}