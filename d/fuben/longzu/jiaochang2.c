
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "��Ĺ");
	set("long", @LONG
���������ʥ�ء�
LONG );
    set("room_hide", 1);
	
	set("objects", ([
		__DIR__"npc/mangseng": 1,
	]));
	setup();
}

void heart_beat()
{
	object *inv;
	inv = all_inventory(this_object());
	if(!sizeof(inv)||(sizeof(inv)==1&&!playerp(inv[0])))
	{
		set_heart_beat(0);
		destruct(this_object());
	}
}
int valid_leave(object me, string dir)
{
	object oba, obb, obc;
	object player;
	object *obs = all_inventory();
	
	oba = present("tu fei", environment(me));
	oba->kill_ob(player);
				player->kill_ob(oba);
	foreach(player in obs) {
		
			
			
				oba->kill_ob(player);
				player->kill_ob(oba);
				
			
		
	}
	return ::valid_leave(me, dir);
}

#include "/fuben/room_fb.h"


