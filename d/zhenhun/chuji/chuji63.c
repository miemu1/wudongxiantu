 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"north" : __DIR__"chuji62",
	"east" : __DIR__"chuji64",
	"west" : __DIR__"chuji2",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}