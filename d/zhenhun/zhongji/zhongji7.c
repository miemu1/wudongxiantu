 

inherit ROOM;

void create()
{
	set("short", "�м���");
	set("long", @LONG
�м���
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji2",
	"north" : __DIR__"zhongji9",
	"east" : __DIR__"zhongji62",
	"west" : __DIR__"zhongji4",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}