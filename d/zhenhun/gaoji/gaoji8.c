 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji6",
	"north" : __DIR__"gaoji22",
	"east" : __DIR__"gaoji5",
	"west" : __DIR__"gaoji34",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}