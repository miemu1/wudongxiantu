

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","挂机房");
	set("long","武林风雨与我何干，不如在此谈天论地。");
	set("close_vip666", 1);
	set("no_fight", 1);
	set("close_room", 1);

	set("valid_startroom", 1);
	set("action_list", ([
		HIY"更新听雨阁"NOR:"update /d/city/tingyvge",
	]));
	set("exits", ([
		"east": __DIR__"tingyvge2",


	]));
	set("no_sleep_room",1);
	setup();
}
