 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji5",
	"north" : __DIR__"zhongji11",
	"east" : __DIR__"zhongji21",
	"west" : __DIR__"zhongji22",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}