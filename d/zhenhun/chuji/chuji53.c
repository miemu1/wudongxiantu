 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji54",
	"north" : __DIR__"chuji52",
	"east" : __DIR__"chuji38",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}