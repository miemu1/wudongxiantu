 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji62",
	"north" : __DIR__"gaoji60",
	"east" : __DIR__"gaoji66",
	"west" : __DIR__"gaoji9",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}