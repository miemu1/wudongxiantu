 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"north" : __DIR__"chuji38",
	"east" : __DIR__"chuji36",
	"west" : __DIR__"chuji54",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}