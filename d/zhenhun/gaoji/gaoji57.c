 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji58",
	"north" : __DIR__"gaoji56",
	"east" : __DIR__"gaoji70",
	"west" : __DIR__"gaoji18",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}