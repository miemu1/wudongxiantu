// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIR "剑宫"NOR);
	set("long", @LONG
禁地的剑宫之处，蕴含着各种奇兵异宝。每次蜀山对决掌门都会从其中挑选赏赐弟子！四面八方的武器发出淡淡的寒意。
LONG
	);
	set("no_fly",1);
	set("exits", ([
		"east" : __DIR__"a1",
		"south" : __DIR__"room0",
		"west" : __DIR__"a2",
         "north" : __DIR__"b",
	]));
	set("objects", ([
   __DIR__"npc/a2":3,
	]));
	setup();
}

