 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"north" : __DIR__"gaoji7",
	"east" : __DIR__"gaoji63",
	"west" : __DIR__"gaoji1",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}