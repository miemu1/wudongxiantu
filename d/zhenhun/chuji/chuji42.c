 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji41",
	"north" : __DIR__"chuji43",
	"east" : __DIR__"chuji31",
	"west" : __DIR__"chuji49",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}