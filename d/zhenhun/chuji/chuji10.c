 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji5",
	"north" : __DIR__"chuji11",
	"east" : __DIR__"chuji21",
	"west" : __DIR__"chuji22",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}