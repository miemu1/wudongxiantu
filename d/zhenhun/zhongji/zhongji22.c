 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji8",
	"north" : __DIR__"zhongji23",
	"east" : __DIR__"zhongji10",
	"west" : __DIR__"zhongji33",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}