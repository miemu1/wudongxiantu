 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji69",
	"north" : __DIR__"chuji71",
	"east" : __DIR__"chuji75",
	"west" : __DIR__"chuji57",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}