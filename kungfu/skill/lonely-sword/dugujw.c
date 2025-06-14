// kuang.c 独孤剑舞

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "独孤"ZJBR"剑舞"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int count;
	int i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「独孤剑舞」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("「独孤剑舞」开始时必须拿着一把剑！\n");


	if ((int)me->query("neili") < 200)
		return notify_fail("你的真气不够，无法施展独孤剑舞！\n");

	if (me->query_skill("lonely-sword") < 200)
		return notify_fail("你的独孤九剑还不到家，无法使用「独孤剑舞」！\n");

	if ((int)me->query_skill("force") < 100 )
		return notify_fail("你的内功火候不够！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "大喝一声，手中的" + weapon->name() +
	      HIC "犹如狂风疾电一般劈向$n" HIC "！\n"
	      HIC "霎时间只见十道剑气层层叠叠如波浪般汹涌而起，$n"
	      HIC "只觉得呼吸登时不畅。"NOR"\n";
	message_combatd(msg, me, target);
	me->add("neili", -200);

	count = me->query_skill("sword") / 2;
	me->add_temp("apply/attack", count);

	for (i = 0; i < 8; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}


	me->add_temp("apply/attack", -count);
	me->start_busy(2 + random(4));
	return 1;
}
