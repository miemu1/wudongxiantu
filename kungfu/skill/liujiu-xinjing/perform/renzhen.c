#include <ansi.h>
inherit F_SSERVER;
string query_name() { return "认真"ZJBR"一剑"; }
int perform(object me, object target)
{
        int lvl, j,i;
	object weapon;
	lvl = me->query_skill("sword", 1);

	if( !target ) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("你只能对战斗中的对手使用认真一剑。\n");

	if( me->query_skill("liujiu-xinjing", 1) < 160 )
		return notify_fail("你的六九心经不够娴熟，无法施展出认真一剑。\n");

	weapon = me->query_temp("weapon");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	      (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");


	if ( me->query("max_neili") < 2000)
		return notify_fail("你的内力不够，无法施展出认真一剑。\n");

	if ( me->query("neili") < 1000)
		return notify_fail("你的真气不够，无法施展出认真一剑。\n");

	if ( me->query("jingli") < 1000)
		return notify_fail("你的精气不够，无法施展出认真一剑。\n");
	if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	message_vision(HIB"$N使出六九心经「认真一剑」，迅捷无比的攻向$n！\n"NOR,me, target);

	j = lvl*10;

	if ( lvl > 200 )
		j = (lvl+me->query("bodyreset") + me->query_skill("liujiu-xinjing", 1) + me->query_skill("martial-cognize", 1) + me->query_skill("force") + me->query_skill("sword")+me->query_skill("unarmed"))*5;

	me->add_temp("apply/attack", j);
	me->add_temp("apply/sword", j);
	me->add_temp("apply/damage", j);

        message_vision(HIB"$N连出数剑，一剑比一剑凌利！\n"NOR,me,target);
        i=0;
        if(random(me->query("combat_exp"))>target->query("combat_exp"))
        {
        	message_vision(HIB"$n连连後退，陷入一片混乱之中，更别说攻击了。\n"NOR,me,target);
        	i=1;
        }
        else
        message_vision(HIB"$n连连後退，防守尚有困难，更别说攻击了。\n"NOR,me,target);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        
	if ( me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);

	if ( me->is_fighting(target))
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        me->add_temp("apply/attack", -j );
        me->add_temp("apply/sword", -j);
        me->add_temp("apply/damage",-j);

        me->start_perform(3+random(2), "「认真一剑」");
		me->start_busy( 1+random(2) );
	me->add("neili", -400);
	me->add("jingli", -150);
	if(i==1) target->start_busy( lvl/50 ); 
	return 1;
}

string perform_name(){ return HIB"认真一剑"NOR; }

