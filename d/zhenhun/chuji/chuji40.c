 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji39",
	"north" : __DIR__"chuji41",
	"east" : __DIR__"chuji33",
	"west" : __DIR__"chuji51",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}