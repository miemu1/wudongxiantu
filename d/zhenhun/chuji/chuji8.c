 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji6",
	"north" : __DIR__"chuji22",
	"east" : __DIR__"chuji5",
	"west" : __DIR__"chuji34",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}