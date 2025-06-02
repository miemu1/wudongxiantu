// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIW"后山小路"NOR);
	set("long", @LONG
这是一条通往后山的快捷小路。
LONG
	);
	set("exits", ([
		"southwest" : __DIR__"room8",
		"northeast" : __DIR__"room10",
	]));
	set("objects", ([
		__DIR__"npc/a6": 8,
	__DIR__"npc/a8": 1,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba;
	object player;
	object *obs = all_inventory();
	
	oba = present("a6"||"a8", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && (dir == "southwest")||oba&& (dir == "northeast")) {
				oba->kill_ob(player);
				player->kill_ob(oba);
				return notify_fail(oba->name()+"喝到：“何足恋也。“\n");
			}
		}
	}
	return ::valid_leave(me, dir);
}
