 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji4",
	"north" : __DIR__"zhongji10",
	"east" : __DIR__"zhongji9",
	"west" : __DIR__"zhongji8",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}