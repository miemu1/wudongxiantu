 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji20",
	"north" : __DIR__"chuji18",
	"east" : __DIR__"chuji58",
	"west" : __DIR__"chuji12",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}