 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji1",
	"north" : __DIR__"gaoji5",
	"east" : __DIR__"gaoji7",
	"west" : __DIR__"gaoji6",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}