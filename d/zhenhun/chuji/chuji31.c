 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji32",
	"north" : __DIR__"chuji30",
	"east" : __DIR__"chuji24",
	"west" : __DIR__"chuji42",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}