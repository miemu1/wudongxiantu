 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji33",
	"north" : __DIR__"chuji31",
	"east" : __DIR__"chuji23",
	"west" : __DIR__"chuji41",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}