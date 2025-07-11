// xue.c 八风拂面

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "八风"ZJBR"拂面"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「八风拂面」只能对战斗中的对手使用。\n");
		
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("「八风拂面」必须空手！\n");

	if ((int)me->query("neili") < 250)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功火候不够！\n");

	if ((int)me->query_skill("xiaoao-quan", 1) < 1)
		return notify_fail("你的笑傲八风还不到家，无法使用八风拂面！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N" HIW "使出致命绝技「八风拂面」，招式变得不清不楚！"NOR"\n";
	message_combatd(msg, me);
	me->add("neili", -250);
	//只对自己的师门npc有秒杀效果
 if (target->query_temp("quester")==getuid(me)&&me->query("combat_exp")<250000000)//师门怪物直接死
 {
 target->receive_wound("qi", 5, me);
  target->die(me);
  	message_combatd("结果$N一击致命，$n吐血不止，立刻身亡！\n", me);
  }
  else
  {
  	target->receive_wound("qi", 1, me);
  	message_combatd("$N使出笑傲八风绝技八风拂面，对敌人没有任何伤害。\n", me);
  }/*
	for (i = 0; i < 5; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}*/

	me->start_busy(1 + random(4));
	return 1;
}
