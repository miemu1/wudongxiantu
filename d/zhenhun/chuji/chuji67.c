 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji66",
	"north" : __DIR__"chuji68",
	"east" : __DIR__"chuji78",
	"west" : __DIR__"chuji60",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}