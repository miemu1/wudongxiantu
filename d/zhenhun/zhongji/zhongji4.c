 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji1",
	"north" : __DIR__"zhongji5",
	"east" : __DIR__"zhongji7",
	"west" : __DIR__"zhongji6",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}