 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji60",
	"north" : __DIR__"chuji58",
	"east" : __DIR__"chuji68",
	"west" : __DIR__"chuji20",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}