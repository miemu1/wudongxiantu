 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji34",
	"north" : __DIR__"gaoji32",
	"east" : __DIR__"gaoji22",
	"west" : __DIR__"gaoji40",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}