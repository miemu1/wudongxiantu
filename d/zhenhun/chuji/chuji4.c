 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji1",
	"north" : __DIR__"chuji5",
	"east" : __DIR__"chuji7",
	"west" : __DIR__"chuji6",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}