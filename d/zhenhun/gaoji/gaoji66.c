 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji65",
	"north" : __DIR__"gaoji67",
	"east" : __DIR__"gaoji79",
	"west" : __DIR__"gaoji61",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}