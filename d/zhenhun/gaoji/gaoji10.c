 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji5",
	"north" : __DIR__"gaoji11",
	"east" : __DIR__"gaoji21",
	"west" : __DIR__"gaoji22",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}