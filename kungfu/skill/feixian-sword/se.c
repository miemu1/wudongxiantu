// ci.c

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "神门刺"; }

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp;


	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	skill = me->query_skill("feixian-sword", 1);

	if (! target || ! me->is_fighting(target))
		return notify_fail("神门刺只能对战斗中的对手使用。\n");

	if (! objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("对方没有使用兵器，你用了神门刺也没用。\n");

	if (skill < 125)
		return notify_fail("你的飞仙剑诀等级不够, 无法施展神门刺。\n");

	if (me->query("neili") < 500)
		return notify_fail("你的内力不够，无法施展神门刺！\n");

	if (me->query_skill_mapped("sword") != "feixian-sword")
		return notify_fail("你现在没有激发飞仙剑诀，无法施展次绝技。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "突然$N" HIY "一声冷哼，手中" + weapon->name() + NOR HIY
		  "中攻直进，直刺$n拿着的" +weapon2->name() + NOR HIY "的"
		  "手。"NOR"\n";
	message_combatd(msg, me, target);

	ap = me->query_skill("sword");
	dp = target->query_skill("parry");

	if (dp < 1) dp = 1;

	if (ap + random(ap) > dp)
	{
		me->add("neili", -500);
		msg = HIR "$n" HIR "只觉手心一阵刺痛，手中" + weapon2->name() + HIR
		      "再也拿捏不住，脱手而飞！"NOR"\n";
		me->start_busy(2 + random(1));
		weapon2->move(environment(target));
	} else
	{
		me->add("neili", -500);
		msg = CYN "可是$n" CYN "看破了$N" CYN "的企图，将手中兵刃挥"
		      "舞得密不透风，挡开了$N" CYN "的兵器。"NOR"\n";
		me->start_busy(4);
	}

	message_combatd(msg, me, target);
	return 1;
}
