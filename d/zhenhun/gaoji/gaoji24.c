 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji23",
	"north" : __DIR__"gaoji25",
	"east" : __DIR__"gaoji12",
	"west" : __DIR__"gaoji31",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}