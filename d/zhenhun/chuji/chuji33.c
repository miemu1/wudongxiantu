 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji34",
	"north" : __DIR__"chuji32",
	"east" : __DIR__"chuji22",
	"west" : __DIR__"chuji40",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}