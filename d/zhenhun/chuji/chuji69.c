 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji68",
	"north" : __DIR__"chuji70",
	"east" : __DIR__"chuji76",
	"west" : __DIR__"chuji58",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}