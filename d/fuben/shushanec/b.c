// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", MAG "天倾"NOR);
	set("long", @LONG
禁地的尽头，蜀山各代掌门之灵，他们是守护蜀山的最后一道保障，不是生死存亡不可出手！

LONG
	);
	set("no_fly",1);
	set("exits", ([
		"east" : __DIR__"b1",
		"south" : __DIR__"a",
		"west" : __DIR__"b2",
	]));
	set("objects", ([
   __DIR__"npc/a4":3,
	]));
	setup();
}

