 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji21",
	"north" : __DIR__"chuji19",
	"east" : __DIR__"chuji59",
	"west" : __DIR__"chuji11",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}