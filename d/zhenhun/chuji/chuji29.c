 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji30",
	"north" : __DIR__"chuji28",
	"east" : __DIR__"chuji26",
	"west" : __DIR__"chuji44",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}