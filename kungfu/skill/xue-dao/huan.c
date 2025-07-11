// huan.c 血刀「幻影」

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "血刀"ZJBR"幻影"; }
string *pfm_type() { return ({ "blade", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp,num;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("血刀「幻影」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
		
	if ((int)me->query_skill("xue-dao", 1) < 80)
		return notify_fail("你的血刀不够娴熟，不会使用「幻影」。\n");

	if (me->query("neili") < 60)
		return notify_fail("你现在真气不够，无法使用「幻影」。\n");

	if (me->query_skill_mapped("blade") != "xue-dao")
		return notify_fail("你没有激发血刀，不能使用「幻影」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "使出血刀绝技，把手中的" +
	      weapon->name() + HIR "舞得飞快，幻起层层刀影逼向$n"
	      HIR "！\n";

	me->add("neili", -50);
	ap = me->query_skill("xue-dao",1)*2;
	dp = target->query_skill("force",1)*2;

num = ap/50  + 2;
if (num>25) num=25;
if (me->query_skill("zuoyou-hubo", 1) > 300)
{
	if (ap *3/10 + random(ap) > dp)
	{
		msg += HIR "结果$p" HIR "被$P" HIR "闹个手忙脚乱，"
		       "只能紧守门户，不敢擅动！"NOR"\n";
		target->start_busy(num);
		me->start_busy(2);
	} else
	{
		msg += "可是$p" HIR "看破了$P" HIR "的企图，并"
		       "不慌张，应对自如。"NOR"\n";
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
}else
{
	if (ap /2 + random(ap) > dp)
	{
		msg += HIR "结果$p" HIR "被$P" HIR "闹个手忙脚乱，"
		       "只能紧守门户，不敢擅动！"NOR"\n";
		target->start_busy(num);
		me->start_busy(2);
	} else
	{
		msg += "可是$p" HIR "看破了$P" HIR "的企图，并"
		       "不慌张，应对自如。"NOR"\n";
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
}

	return 1;
}
