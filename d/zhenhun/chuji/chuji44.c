 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji43",
	"north" : __DIR__"chuji45",
	"east" : __DIR__"chuji29",
	"west" : __DIR__"chuji47"
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	"/d/zhenhun/npc/qiutu1b" : 1 + random(3),
	]));
	setup();
}