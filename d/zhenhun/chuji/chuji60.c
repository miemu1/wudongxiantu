 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji61",
	"north" : __DIR__"chuji59",
	"east" : __DIR__"chuji67",
	"west" : __DIR__"chuji21",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}