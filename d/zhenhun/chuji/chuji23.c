 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji22",
	"north" : __DIR__"chuji24",
	"east" : __DIR__"chuji11",
	"west" : __DIR__"chuji32",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}