 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji18",
	"north" : __DIR__"chuji16",
	"east" : __DIR__"chuji56",
	"west" : __DIR__"chuji14",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}