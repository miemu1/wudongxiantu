 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji31",
	"north" : __DIR__"gaoji29",
	"east" : __DIR__"gaoji25",
	"west" : __DIR__"gaoji43",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}