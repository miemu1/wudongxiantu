 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji58",
	"north" : __DIR__"chuji56",
	"east" : __DIR__"chuji70",
	"west" : __DIR__"chuji18",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}