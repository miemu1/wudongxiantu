 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji2",
	"north" : __DIR__"chuji9",
	"east" : __DIR__"chuji62",
	"west" : __DIR__"chuji4",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}