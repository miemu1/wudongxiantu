 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji25",
	"north" : __DIR__"chuji27",
	"east" : __DIR__"chuji14",
	"west" : __DIR__"chuji29",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}