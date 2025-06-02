#include <ansi.h>
#include <armor.h>

inherit CHIBANG;
inherit F_GEMS;

void init_sockets(object me)
{
	set("max_sockets", 3);
	if (me->query("combat_exp") > 10000000)
		add("max_sockets", 1);

	if (me->query("combat_exp") < 10000000 && (int)query("sockets/max",1)>=3)
        set("sockets/max",3);

	if (me->query("combat_exp") < 20000000 && (int)query("sockets/max",1)>=4)
        set("sockets/max",4);

	if ((int)query("sockets/max",1)>5)
        set("sockets/max",5);

	if (me->query("diablo/" + TYPE_SHOUHUAN + "/id") != query("id")) return;

	set("sockets", me->query("diablo/" + TYPE_SHOUHUAN + "/sockets"));
	set_armor_desc();
}

void setup()
{
	init_sockets(this_player());
	::setup();
}
