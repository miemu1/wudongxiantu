 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji25",
	"north" : __DIR__"gaoji27",
	"east" : __DIR__"gaoji14",
	"west" : __DIR__"gaoji29",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}