 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"north" : __DIR__"zhongji65",
	"east" : __DIR__"zhongji81",
	"west" : __DIR__"zhongji63",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}