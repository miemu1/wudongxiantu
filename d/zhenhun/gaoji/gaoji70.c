 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji69",
	"north" : __DIR__"gaoji71",
	"east" : __DIR__"gaoji75",
	"west" : __DIR__"gaoji57",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}