 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji19",
	"north" : __DIR__"chuji17",
	"east" : __DIR__"chuji57",
	"west" : __DIR__"chuji13",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}