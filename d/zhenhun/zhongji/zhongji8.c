 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji6",
	"north" : __DIR__"zhongji22",
	"east" : __DIR__"zhongji5",
	"west" : __DIR__"zhongji34",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}