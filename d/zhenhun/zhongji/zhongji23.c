 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji22",
	"north" : __DIR__"zhongji24",
	"east" : __DIR__"zhongji11",
	"west" : __DIR__"zhongji32",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}