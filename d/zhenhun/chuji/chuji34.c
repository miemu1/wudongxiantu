 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji35",
	"north" : __DIR__"chuji33",
	"east" : __DIR__"chuji8",
	"west" : __DIR__"chuji39",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}