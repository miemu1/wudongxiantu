 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji9",
	"north" : __DIR__"chuji20",
	"east" : __DIR__"chuji60",
	"west" : __DIR__"chuji10",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}