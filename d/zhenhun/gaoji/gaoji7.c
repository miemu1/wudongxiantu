 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji2",
	"north" : __DIR__"gaoji9",
	"east" : __DIR__"gaoji62",
	"west" : __DIR__"gaoji4",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}