 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji42",
	"north" : __DIR__"chuji44",
	"east" : __DIR__"chuji30",
	"west" : __DIR__"chuji48",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}