// chan.c 太极剑法「缠」字诀

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "缠字诀"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	int level,ap,dp,num;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("太极剑法「缠」字诀只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
		
	if ((level = me->query_skill("taiji-jian", 1)) < 80)
		return notify_fail("你的太极剑法不够娴熟，不会使用「缠」字诀。\n");

	if (me->query_skill_mapped("sword") != "taiji-jian")
		return notify_fail("你必须激发太极剑法才能使用「缠」字诀。\n");

	if (me->query("neili") < 100)
		return notify_fail("你现在真气不够，无法使用「缠」字诀。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIG "$N" HIG "使出太极剑法「缠」字诀，剑意圈转，连"
	      "绵不绝，连递数个虚招企图扰乱$n" HIG "的攻势。"NOR"\n";

	me->add("neili", -100);
	
	ap = level * 2;
	dp = target->query_skill("parry", 1) * 2;

num = ap/50  + 2;
if (num>25) num=25;
if (me->query_skill("zuoyou-hubo", 1) > 300)
{
	if (ap *3/10 + random(ap) > dp)
	{
		msg += HIR "结果$p" HIR "被$P" HIR "闹个手忙脚乱，"
		       "惊慌失措，呆在当场，不知如何应对！"NOR"\n";
		target->start_busy(num);
		me->start_busy(1);
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，镇"
		       "定逾恒，全神应对自如。"NOR"\n";
		me->start_busy(2);
	}
	message_combatd(msg, me, target);
}else
{
	if (ap /2 + random(ap) > dp)
	{
		msg += HIR "结果$p" HIR "被$P" HIR "闹个手忙脚乱，"
		       "惊慌失措，呆在当场，不知如何应对！"NOR"\n";
		target->start_busy(num);
		me->start_busy(1);
	} else
	{
		msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，镇"
		       "定逾恒，全神应对自如。"NOR"\n";
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
}	

	return 1;
}
