 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji3",
	"north" : __DIR__"gaoji8",
	"east" : __DIR__"gaoji4",
	"west" : __DIR__"gaoji35",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}