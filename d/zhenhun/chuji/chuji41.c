 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji40",
	"north" : __DIR__"chuji42",
	"east" : __DIR__"chuji32",
	"west" : __DIR__"chuji50",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}