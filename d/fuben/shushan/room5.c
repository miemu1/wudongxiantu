// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIR "炼丹房"NOR);
	set("long", @LONG
这里是蜀山的炼丹房。
LONG
	);
	set("exits", ([
		"west" : __DIR__"room3",
	]));
	set("objects", ([
		__DIR__"npc/a5": 4,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba, obb, obc;
	object player;
	object *obs = all_inventory();
	
	oba = present("a5", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && dir == "west") {
				oba->kill_ob(player);
				player->kill_ob(oba);
				return notify_fail(oba->name()+"淡淡道：“故尝无欲，以观奇妙！”\n");
			}
		}
	}
	return ::valid_leave(me, dir);
}
