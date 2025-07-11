// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "北冥"ZJBR"战气"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用北冥神功提升自己的战斗力。\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");

	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIG "$N" HIG "将内力运遍浑身诸大要穴，"
			"然后收气丹田，双目一睁，登时精光四射！"NOR"\n", me);

	me->add_temp("apply/damage", skill/3);
	me->add_temp("apply/unarmed_damage", skill/3);
	me->add_temp("apply/attack", skill / 3);
	me->add_temp("apply/dodge", skill / 3);
	me->add_temp("apply/parry", skill / 3);
	me->add_temp("apply/defense", skill / 3);
	me->set_temp("powerup", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill / 3 :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("powerup"))
	{
		me->add_temp("apply/damage", -amount);
	me->add_temp("apply/unarmed_damage",-amount);
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/dodge", -amount);
	me->add_temp("apply/parry", -amount);
	me->add_temp("apply/defense", -amount);
		me->add_temp("apply/defense", -amount);
		me->delete_temp("powerup");
		tell_object(me, "你的北冥神功运行完毕，将内力收回丹田。\n");
	}
}

