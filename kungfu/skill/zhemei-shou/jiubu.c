// jiubu.c 九部式

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "九部式"; }
string *pfm_type() { return ({ "hand", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int ap, dp, count, i;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「九部式」只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("zhemei-shou", 1) < 120)
		return notify_fail("你的折梅手法不够娴熟，不会使用「九部式」。\n");
				
	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功修为不够高，难以运用「九部式」。\n");
			
	if ((int)me->query("neili") < 100)
		return notify_fail("你现在真气不够，不能使用「九部式」。\n");

	if (me->query_skill_mapped("hand") != "zhemei-shou")
		return notify_fail("你没有准备天山折梅手，不能使用「九部式」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	if (me->query_skill("tianchang-dijiu", 1) > 49||me->query_skill("tiandi-xiaoyao", 1) > 49)
	{
	msg = HIC "$N" HIC "双手虚虚实实的抓向$n"HIC "的要害，身法缥缈，手式奇特，令人难以捉摸。"NOR"\n";

	ap = me->query_skill("hand");
	dp = target->query_skill("force");
	if (ap / 2 + random(ap) > dp)
	{
		count = ap / 12;
		msg += HIY "$n" HIY "见$P" HIY "这一招奇诡异常，不由大吃一惊，慌乱中破绽迭出。"NOR"\n";
	} else
	{
		msg += HIC "$n" HIC "不敢小觑$P" HIC
		       "的来招，腾挪躲闪，小心招架。"NOR"\n";
		count = 0;
	}

	message_combatd(msg, me, target);
	me->add_temp("apply/attack", count);

	me->add("neili", -200);
	for (i = 0; i < 8; i++)
	{
		if (! me->is_fighting(target))
			break;
		if (random(3) == 0 && ! target->is_busy())
			target->start_busy(1);

		COMBAT_D->do_attack(me, target, 0, 0);
	}

	me->start_busy(2 + random(7));
	me->add_temp("apply/attack", -count);
	}
else
{
	msg = HIC "$N" HIC "双手虚虚实实的抓向$n"
	      HIC "的要害，身法缥缈，手式奇特，令人难以捉摸。"NOR"\n";

	me->add("neili", -50);
	ap = me->query_skill("hand");
	dp = target->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
	{
		damage = me->query_skill("zhemei-shou", 1);
		damage += random(damage);
		me->add("neili", -100);

		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65,
					   HIR "$p" HIR "一个闪避不及，结果被$P"
					   HIR "抓了个正中，浑身内息不由得一滞，气血翻涌。"NOR"\n");
		me->start_busy(2);
	} else 
	{
		msg += HIC "可是$p" HIC "身手敏捷，巧妙的躲过了$P"
		       HIC "的攻击！"NOR"\n";
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
}

	return 1;
}
