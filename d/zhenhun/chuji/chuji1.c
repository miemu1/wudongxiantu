 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji",
	"north" : __DIR__"chuji4",
	"east" : __DIR__"chuji2",
	"west" : __DIR__"chuji3",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}