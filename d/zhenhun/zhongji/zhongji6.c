 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji3",
	"north" : __DIR__"zhongji8",
	"east" : __DIR__"zhongji4",
	"west" : __DIR__"zhongji35",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}