 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji22",
	"north" : __DIR__"gaoji24",
	"east" : __DIR__"gaoji11",
	"west" : __DIR__"gaoji32",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}