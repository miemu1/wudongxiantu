 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"north" : __DIR__"chuji35",
	"east" : __DIR__"chuji3",
	"west" : __DIR__"chuji37",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}