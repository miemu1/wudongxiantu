 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji57",
	"north" : __DIR__"chuji55",
	"east" : __DIR__"chuji71",
	"west" : __DIR__"chuji17",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}