//changduan.c -「烛影斧声」
// Modified by Venus Oct.1997
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int extra,damage;
	string msg;
	extra=me->query_skill("taizu-quan",1);
	if( !target ) target = offensive_target(me);
	if( !target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("你只能对战斗中的对手使用「烛影斧声」。\n");
	if (me->query_skill_mapped("unarmed") != "taizu-quan")
		return notify_fail("你没正确激发该技能 。\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if( (int)me->query_skill("taizu-quan",1) < 100)
		return notify_fail("你目前功力还使不出「烛影斧声」。\n");
    if( objectp(me->query_temp("weapon")) )
        return notify_fail("你必须空手才能使用「烛影斧声」！\n");  
	if( (int)me->query("neili") < 200 )
		return notify_fail("你的内力不够。\n");
	me->add("neili", -100);
	msg = HIC"只见$n眼前一暗，三个硕大的拳头就挥来了，噗通几声！"NOR;
	message_vision(msg, me, target);
	damage = extra + random(extra);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		target->receive_damage("qi", damage,me);
//		target->receive_wound("qi", damage,me);
	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"。\n" NOR);
	me->start_busy(2);
	//if (!target->is_busy()) target->start_busy(random(2));
	
	return 1;
}

