 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji63",
	"north" : __DIR__"gaoji61",
	"east" : __DIR__"gaoji65",
	"west" : __DIR__"gaoji7",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}