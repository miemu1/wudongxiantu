 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji",
	"north" : __DIR__"gaoji4",
	"east" : __DIR__"gaoji2",
	"west" : __DIR__"gaoji3",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}