 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji67",
	"north" : __DIR__"chuji69",
	"east" : __DIR__"chuji77",
	"west" : __DIR__"chuji59",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}