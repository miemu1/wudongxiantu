 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji13",
	"north" : __DIR__"gaoji15",
	"east" : __DIR__"gaoji17",
	"west" : __DIR__"gaoji26",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}