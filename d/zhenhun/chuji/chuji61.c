 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji62",
	"north" : __DIR__"chuji60",
	"east" : __DIR__"chuji66",
	"west" : __DIR__"chuji9",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	]));
	setup();
}