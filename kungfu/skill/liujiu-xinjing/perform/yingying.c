// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

string query_name() { return "嘤嘤"ZJBR"乱拳"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count;
        int i;

		if (! target) target = offensive_target(me);
        if (! target || ! me->is_fighting(target))
                return notify_fail("嘤嘤乱拳只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("嘤嘤乱拳只能空手施展。\n");

        if (me->query("max_neili") < 6000)
                return notify_fail("你的内力的修为不够，现在无法使用嘤嘤乱拳。\n");

        if (me->query_skill("liujiu-xinjing", 1) < 200)
                return notify_fail("你的六九心经还不够娴熟，难以施展嘤嘤乱拳。\n");

        if (me->query_skill_mapped("unarmed") != "liujiu-xinjing")
                return notify_fail("你现在没有激发六九心经为拳脚，难以施展嘤嘤乱拳。\n");

        if (me->query_skill_mapped("force") != "liujiu-xinjing")
                return notify_fail("你现在没有激发六九心经为内功，难以施展嘤嘤乱拳。\n");

        if (me->query_skill_prepared("unarmed") != "liujiu-xinjing")
                return notify_fail("你现在没有准备使用六九心经，难以施展嘤嘤乱拳。\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("你的真气不够，无法运用嘤嘤乱拳。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIR "嘤嘤怪叫一声，双拳"
              "胡乱舞出，朝向$n" HIR "疯狂打去。\n" NOR;

        ap = me->query_skill("unarmed");
        dp = target->query_skill("parry");

        if (ap*2/3 + random(ap) > dp)
        {
                count = ap*20;
                msg += HIY "$n" HIY "只觉对方好生有趣，"
                       "一时不查，竟然被连打数下。\n" NOR;
        } else
        {
                msg += HIY "$n" HIY "看到$N" HIY "一声怪叫，"
                       "连忙捂住面庞，快速跑开。\n" NOR;
                count = ap*5;
        }

        message_vision(msg, me, target);
        me->add_temp("apply/attack", count);
        me->add_temp("apply/unarmed_damage", count);

        me->add("neili", -300);

        for (i = 0; i < 8; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(5) < 2 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(1 + random(5));
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/unarmed_damage", -count);

        return 1;
}

