 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"north" : __DIR__"zhongji6",
	"east" : __DIR__"zhongji1",
	"west" : __DIR__"zhongji36",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}