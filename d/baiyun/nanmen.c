// Room: /d/fuzhou/nanmen.c
inherit ROOM;

void create()
{
	set("short", "皇宫");
	set("long", @LONG
依旧冰, 寒。仿佛这里存在的意义便是为了孤独..孤独..只是为了这个人吧。。
LONG );
	set("exits", ([
		"south" : __DIR__"zhongzhou",
		"north" : __DIR__"nanmendou",
	]));
	set("objects", ([
		//	"/kungfu/class/baiyun/ye" : 1,
	]));
set("outdoors", "by");
	setup();
}

