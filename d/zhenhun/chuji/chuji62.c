 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji63",
	"north" : __DIR__"chuji61",
	"east" : __DIR__"chuji65",
	"west" : __DIR__"chuji7",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}