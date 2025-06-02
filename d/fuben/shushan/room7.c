// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", MAG"后山小路"NOR);
	set("long", @LONG
这是一条通往后山的快捷小路。
LONG
	);
	set("exits", ([
		"southwest" : __DIR__"room6",
		"northeast" : __DIR__"room8",
	]));
	set("objects", ([
		__DIR__"npc/a6": 4,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba, obb, obc;
	object player;
	object *obs = all_inventory();
	
	oba = present("a6",environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && dir == "northeast"||oba && dir == "southwest") {
				oba->kill_ob(player);
				player->kill_ob(oba);
				return notify_fail(oba->name()+"淡淡道：“故尝无欲，以观奇妙！”\n");
			}
		}
	}
	return ::valid_leave(me, dir);
}
