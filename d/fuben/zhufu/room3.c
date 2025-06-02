// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIC"大厅"NOR"");
	set("long", @LONG
这里是朱府的大厅。
LONG
	);
	set("exits", ([
		"northwest" : __DIR__"room5",
		"southwest" : __DIR__"room1",
	]));
	set("action_list",([
		"转动机关":"zhuan",
	]));
	set("objects", ([
		__DIR__"npc/huyuan": 5,
	]));
	setup();
}
int do_zhuan(string arg)
{
	int i;
	object me=this_player();
	object *team;
	if(!team = me->query_team())
    return notify_fail("机关需要组队才能开启！\n");
	if(me->query_temp("dong")!=1)
	{
    call_out("do_decide",2);
	for (i = 0;i < sizeof(team);i ++)
	{
    team[i]->set_temp("dong",1);
    tell_object(team[i],"一阵机械转动的声音传了过来"NOR"\n");
	}
	}else{
    return notify_fail("机关已经被开启！\n");
	}
}
int do_decide(string arg)
{
	int i;
    object me = this_player();
	object *team = me->query_team();
	for (i = 0;i < sizeof(team);i ++)
	{	
    team[i]->delete_temp("dong");
    team[i]->delete_temp("xi");
    tell_object(team[i],HIR"机关自动关闭了"NOR"\n");
	}
}
int valid_leave(object me, string dir)
{
	object oba;
	object player;
	object *obs = all_inventory();
	
	oba = present("hu wei", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && (dir == "northwest") ||oba &&  (dir == "southwest")) {
				oba->kill_ob(player);
				player->kill_ob(oba);
				return notify_fail(oba->name()+"对你大吼道：找死！兄弟们，并肩子上。\n");
			}
		}
	}
			if ((dir == "northwest")) {
		    if(me->query_temp("xi")!=1&&me->query_temp("dong")!=1||!me->query_temp("xi")||!me->query_temp("dong"))
		    return notify_fail("机关尚未打开！\n");
			}
	        if ((dir == "northwest")) {
		      me->delete_temp("xi");
		      me->delete_temp("dong");
			  tell_object(me,"机关关闭！\n");
	          }
	return ::valid_leave(me, dir);
}

#include "/d/fuben/room_fb.h"
