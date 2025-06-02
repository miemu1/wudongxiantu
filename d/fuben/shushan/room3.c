// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
这里是蜀山的广场，无数蜀山弟子在这做早课。
LONG
	);
	set("exits", ([
		"south" : __DIR__"room2",
		"north" : __DIR__"room4",
		"east" : __DIR__"room5",
		"west" : __DIR__"room6",
	]));
	set("objects", ([
		__DIR__"npc/a1": 4,
		__DIR__"npc/a2": 4,
		__DIR__"npc/a3": 4,
		__DIR__"npc/a4": 4,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba, obb, obc;
	object player;
	object *obs = all_inventory();
	
	oba = present("a1"||"a2"||"a3"||"a4", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && dir == "north"||oba && dir == "south"||oba && dir == "east"||oba && dir == "west") {
				oba->kill_ob(player);
				player->kill_ob(oba);
				return notify_fail(oba->name()+"淡淡道：“故尝无欲，以观奇妙！”\n");
			}
		}
	}
	return ::valid_leave(me, dir);
}


