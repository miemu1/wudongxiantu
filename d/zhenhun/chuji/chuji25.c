 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji24",
	"north" : __DIR__"chuji26",
	"east" : __DIR__"chuji13",
	"west" : __DIR__"chuji30",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}