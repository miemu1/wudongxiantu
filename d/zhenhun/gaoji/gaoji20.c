 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji21",
	"north" : __DIR__"gaoji19",
	"east" : __DIR__"gaoji59",
	"west" : __DIR__"gaoji11",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}