 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji36",
	"north" : __DIR__"gaoji34",
	"east" : __DIR__"gaoji6",
	"west" : __DIR__"gaoji38",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}