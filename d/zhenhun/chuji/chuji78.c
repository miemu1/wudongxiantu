 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji79",
	"north" : __DIR__"chuji77",
	"west" : __DIR__"chuji67",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}