 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji3",
	"north" : __DIR__"chuji8",
	"east" : __DIR__"chuji4",
	"west" : __DIR__"chuji35",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}