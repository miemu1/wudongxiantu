 

inherit ROOM;

void create()
{
	set("short", "�߼���");
	set("long", @LONG
�߼���
LONG
	);
	set("exits", ([
	"north" : __DIR__"gaoji65",
	"east" : __DIR__"gaoji81",
	"west" : __DIR__"gaoji63",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	]));
	setup();
}