 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji68",
	"north" : __DIR__"gaoji70",
	"east" : __DIR__"gaoji76",
	"west" : __DIR__"gaoji58",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}