// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIY"万剑阁楼"NOR"");
	set("long", HIY"朽之哀思，思而唉之"NOR"");
	set("exits", ([
		"east" : __DIR__"a"+random(100)+"",
		"south" : __DIR__"a"+random(100)+"",
		"west" : __DIR__"a"+random(100)+"",
		"north" : __DIR__"a"+random(100)+"",
		"northwest" : __DIR__"a"+random(100)+"",
        "northeast" : __DIR__"a"+random(100)+"",
		 "up" : __DIR__"a"+random(100)+"",
		 "southeast" : __DIR__"b0",
		 "southwest" : __DIR__"a"+random(100)+"",
	]));
	set("objects", ([
		//__DIR__"npc/a1": 4,
	     //__DIR__"npc/a2": 4,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba;
	object player;
	object *obs = all_inventory();
	
	oba = present("a1", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && (dir == "east")||oba && (dir == "south")||oba && (dir == "west")||oba && (dir == "north")||oba && (dir == "northwest")||oba && (dir == "northeast")||oba && (dir == "southeast")||oba && (dir == "up")||oba && (dir == "southwest")) {
				//oba->kill_ob(player);
				//player->kill_ob(oba);
				return notify_fail(oba->name()+"喝到：“琵琶声，声声哀之。“\n");
			}
		}
	}
	return ::valid_leave(me, dir);
}
