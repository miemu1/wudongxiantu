 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji23",
	"north" : __DIR__"chuji25",
	"east" : __DIR__"chuji12",
	"west" : __DIR__"chuji31",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}