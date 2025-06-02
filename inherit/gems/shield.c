#include <ansi.h>
#include <armor.h>

inherit SHIELD;
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

	if (me->query("diablo/" + TYPE_SHIELD + "/id") != query("id")) return;

	set("sockets", me->query("diablo/" + TYPE_SHIELD + "/sockets"));
	set_armor_desc();
}

void setup()
{
	init_sockets(this_player());
	::setup();
}

void spec_prop(object me, string socket, int socket_level, int mode)
{
	int i;
	if (!valid_gem(socket, socket_level)) return;
	if (me->query("diablo/" + TYPE_SHIELD + "/id") != query("id")) return;
	if (query("armor_prop/armor") < 20) return;
	switch (socket) {
	case "ruby":
		break;
	case "topaz":
		break;
	case "sapphire":
		break;
	case "emerald":
		break;
	case "amethyst":
		break;
	case "diamond":
		break;
	case "skull":
		break;
	}
	return;
}

int wear()
{
	int i, sockets, ret;
	object me = environment();

	if (!(ret = ::wear())) return 0;
	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), 1);

	remove_call_out("check_fight");
	call_out("check_fight", 1, me);

	return ret;
}

int unequip()
{
	int i, sockets, ret;
	object me = environment();

	if (!(ret = ::unequip())) return 0;
	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), -1);

	remove_call_out("check_fight");

	return ret;
}

int spec_effect(object ob, object me, int damage, string socket, int socket_level)
{
	int i, def = 0;

	if (!valid_gem(socket, socket_level)) return def;
	if (me->query("diablo/" + TYPE_SHIELD + "/id") != query("id")) return 0;
	if (random(100) + me->query_temp("apply/magic") < 70) return def;

	switch (socket) {
	case "ruby":
		break;
	case "topaz":
		break;
	case "sapphire":
		break;
	case "emerald":
		break;
	case "amethyst":
		break;

	case "windjade":
		message_vision(GRN"$nֻ��$N������Χ�γ����罫$p�Ĺ�����ȥ���٣�\n"NOR, me, ob);
		def = -damage * socket_level / 10;
		me->add("qi", socket_level*30);
		me->add("eff_qi", socket_level*30);
		if (def < 1) def=1;

		break;
	case "firejade":
		break;
	case "icejade":
		break;
	case "thunderjade":
		break;
	case "earthjade":

		break;
	case "diamond":

		break;
	case "skull":
		break;
	}
	return def;
}

int ob_hit(object ob, object me, int damage)
{
	int i, sockets, ret = 0;

	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		ret += spec_effect(ob, me, damage,query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)));
	return ret;
}

void spec_recover(object me, string socket, int socket_level)
{
	int i;

//if (ob->query_temp("combat_yield")) return;
	if (!valid_gem(socket, socket_level)) return;
	if (me->query("diablo/" + TYPE_SHIELD + "/id") != query("id")) return;
        if ((int)me->query_temp("combat_yield")==1) return;
	if (random(100) + me->query_temp("apply/magic") < 70) return;

	switch (socket) {
	case "ruby":
		break;
	case "topaz":
		break;
	case "emerald":
		break;
	case "amethyst":
		break;
	case "diamond":
		break;
	case "skull":
		break;
	}
	return;
}

void check_fight(object me)
{
	int i, sockets;

	if (!me || !query("equipped")) return;
	if (me->query("diablo/" + TYPE_SHIELD + "/id") != query("id")) return;
	if (living(me) && me->is_fighting()) {
		sockets = query("sockets/max");
		for (i = 1; i <= sockets; i++)
			spec_recover(me, query(sprintf("sockets/socket%d", i)),query(sprintf("sockets/socket%d_level", i)));
	}

	call_out("check_fight", 1, me);
}
