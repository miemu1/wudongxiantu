 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji8",
	"north" : __DIR__"gaoji23",
	"east" : __DIR__"gaoji10",
	"west" : __DIR__"gaoji33",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}