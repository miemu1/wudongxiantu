 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji36",
	"north" : __DIR__"chuji34",
	"east" : __DIR__"chuji6",
	"west" : __DIR__"chuji38",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}