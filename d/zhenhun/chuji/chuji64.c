 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"north" : __DIR__"chuji65",
	"east" : __DIR__"chuji81",
	"west" : __DIR__"chuji63",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}