 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"north" : __DIR__"chuji7",
	"east" : __DIR__"chuji63",
	"west" : __DIR__"chuji1",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}