 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji12",
	"north" : __DIR__"chuji14",
	"east" : __DIR__"chuji18",
	"west" : __DIR__"chuji25",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}