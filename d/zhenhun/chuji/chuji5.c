 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji4",
	"north" : __DIR__"chuji10",
	"east" : __DIR__"chuji9",
	"west" : __DIR__"chuji8",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}