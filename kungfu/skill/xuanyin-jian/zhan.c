#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	int lvl, j, ap, dp;
	object weapon;
	lvl = me->query_skill("sword", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("你只能对战斗中的对手使用斩字诀。\n");

	weapon = me->query_temp("weapon");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	      (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("xuanyin-jian", 1) < 200 )
		return notify_fail("你的玄阴剑法不够娴熟，无法施展出斩字诀。\n");

	/* if ((int)me->query_skill("jiuyin-zhengong", 1) < 200)
		return notify_fail("你的九阴真功火候不够，无法施展出斩字诀。\n");

	if ((int)me->query_skill("jiuyin-shenfa", 1) < 200)
		return notify_fail("你的九阴身法火候不够，无法施展出斩字诀。\n"); */

	if ( (int)me->query("max_neili") < 2000)
		return notify_fail("你的内力不够，无法施展出斩字诀。\n");

	if ( (int)me->query("neili") < 1500)
		return notify_fail("你的真气不够，无法施展出斩字诀。\n");

	if ((int)me->query("jingli") < 1500)
		return notify_fail("你的精气不够，无法施展出斩字诀。\n");

	message_vision(HIB"\n$N使出九阴「斩字诀」，剑光一瞬间攻向$n！\n"NOR,me, target);

	j = lvl/3 * lvl/8;

	me->add_temp("apply/attack", j);
	me->add_temp("apply/sword", j);
	me->add_temp("apply/damage", j);

	ap = me->query("combat_exp", 1) / 1000 * me->query_dex(1);
	dp = target->query("combat_exp", 1) / 1000 * target->query_dex(1);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	if( random(ap + dp ) > dp ) {
		message_vision(HIB"结果$N一招得手，$n的手腕居然被斩了下来！\n"NOR,me, target);
		target->set_temp("must_be_hit", 1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
		target->delete_temp("must_be_hit");
                target->apply_condition("broken_arm",lvl); 
		me->add("neili", -100);
	}

	me->add_temp("apply/attack", -j);
	me->add_temp("apply/sword", -j);
	me->add_temp("apply/damage",-j);
	me->add("neili", -400);
	me->add("jingli", -150);
	me->start_perform(4,"「斩字诀」");
	me->start_busy(1+random(2));
	return 1;
}

string perform_name(){ return HIB"斩字诀"NOR; }

int help(object me)
{
        write(HIB"\n玄阴剑法之「斩字诀」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 1500 以上；
                最大内力 2000 以上；
                当前精力 1500 以上；
                玄阴剑法等级 200 以上；
                九阴真功等级 200 以上；
                九阴身法等级 200 以上；
                激发剑法为玄阴剑法；
                激发招架为玄阴剑法；
                且手持兵器。

HELP
        );
        return 1;
}
