#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
 
string query_name() { return "九幽"ZJBR"溟毒"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp;
	int damage, lvl;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("九幽溟毒只能对战斗中的对手使用。\n");

	if (me->query_temp("weapon"))
		return notify_fail("你必须是空手才能使用九幽溟毒！\n");
 
	lvl = me->query_skill("mingdu-mojing", 1);

	if (lvl < 300)
		return notify_fail("你的溟毒魔经还不够纯熟！\n");

	if (me->query_skill("force") < 600)
		return notify_fail("你的内功火候太低，无法使出九幽溟毒。\n");

	if (me->query("neili") < 1000)
		return notify_fail("你的内力不够，无法使出九幽溟毒。\n");

	if (me->query_skill_mapped("strike") != "mingdu-mojing")
		return notify_fail("你没有激发溟毒魔经, 不能使用「九幽溟毒」！\n");
 
       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = BLU "$N" BLU "聚气于掌，仰天一声狂啸，刹那间双掌交错，一招"
		  "「九幽溟毒」带着阴毒内劲直贯$n" BLU "！"NOR"\n";

	ap = me->query_skill("strike") + lvl;
	dp = target->query_skill("parry");

	if (dp < 1) dp = 1;

	if ( ap / 2 + random(ap) > dp + random(dp) )
	{
	me->add("neili", -300);
	damage = lvl + random(lvl);
	target->affect_by("ming-du",
		([ "level" : me->query("jiali") + random(me->query("jiali")),
		"id"    : me->query("id"),
		"duration" : lvl / 25 + random(lvl / 20) ]));
	msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 70, 
	       HIR "只听$n" HIR "惨叫一声，只感两耳轰"
	       "鸣，目不视物，喷出一大口鲜血，软软瘫倒。"NOR"\n");

	me->start_busy(2);
	}
    else
	{
	msg += HIY "$p见$P来势汹涌，急忙纵身一跃而起，躲开了这致命的一击！"NOR"\n";
	me->add("neili", -300);
	me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}

