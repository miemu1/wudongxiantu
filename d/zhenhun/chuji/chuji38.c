 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji37",
	"north" : __DIR__"chuji39",
	"east" : __DIR__"chuji35",
	"west" : __DIR__"chuji53",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	"/d/zhenhun/npc/qiutu1b" : 1 + random(3),
	]));
	setup();
}