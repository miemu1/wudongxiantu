 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji8",
	"north" : __DIR__"chuji23",
	"east" : __DIR__"chuji10",
	"west" : __DIR__"chuji33",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}