 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji7",
	"north" : __DIR__"chuji21",
	"east" : __DIR__"chuji61",
	"west" : __DIR__"chuji5",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}