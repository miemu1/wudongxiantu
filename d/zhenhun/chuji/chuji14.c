 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji13",
	"north" : __DIR__"chuji15",
	"east" : __DIR__"chuji17",
	"west" : __DIR__"chuji26",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}