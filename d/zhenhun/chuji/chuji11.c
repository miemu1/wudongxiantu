 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji10",
	"north" : __DIR__"chuji12",
	"east" : __DIR__"chuji20",
	"west" : __DIR__"chuji23",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	"/d/zhenhun/npc/qiutu1b" : 1 + random(3),
	]));
	setup();
}