 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji42",
	"north" : __DIR__"gaoji44",
	"east" : __DIR__"gaoji30",
	"west" : __DIR__"gaoji48",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}