 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji65",
	"north" : __DIR__"chuji67",
	"east" : __DIR__"chuji79",
	"west" : __DIR__"chuji61",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}