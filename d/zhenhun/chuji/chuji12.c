 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji11",
	"north" : __DIR__"chuji13",
	"east" : __DIR__"chuji19",
	"west" : __DIR__"chuji24",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}