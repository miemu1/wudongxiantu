 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji59",
	"north" : __DIR__"chuji57",
	"east" : __DIR__"chuji69",
	"west" : __DIR__"chuji19",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}