 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji18",
	"north" : __DIR__"gaoji16",
	"east" : __DIR__"gaoji56",
	"west" : __DIR__"gaoji14",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}