 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji38",
	"north" : __DIR__"chuji40",
	"east" : __DIR__"chuji34",
	"west" : __DIR__"chuji52",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}