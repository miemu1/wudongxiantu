 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji66",
	"north" : __DIR__"gaoji68",
	"east" : __DIR__"gaoji78",
	"west" : __DIR__"gaoji60",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}