 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji4",
	"north" : __DIR__"gaoji10",
	"east" : __DIR__"gaoji9",
	"west" : __DIR__"gaoji8",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}