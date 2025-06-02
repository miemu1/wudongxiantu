// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", WHT"剑宫"NOR);
	set("long", @LONG
剑宫的某一处武器库，藏着应接不暇的各种武器。虽比不上剑宫的武器但也不逊色于世间流传兵器。守护者暗藏其中稍有风吹草动便会将来犯者处决。
LONG
	);
			set("no_fly",1);
	set("exits", ([
		"east" : __DIR__"a3",
		"west" : __DIR__"a",
	]));
	set("objects", ([
   __DIR__"npc/a2":3,
	]));
	setup();
}

