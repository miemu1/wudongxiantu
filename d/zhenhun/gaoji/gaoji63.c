 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"north" : __DIR__"gaoji62",
	"east" : __DIR__"gaoji64",
	"west" : __DIR__"gaoji2",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}