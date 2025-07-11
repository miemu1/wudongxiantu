#include <ansi.h>
#include <combat.h>

#define FEI "「" HIY "飞龙在天" NOR "」"
string query_name() { return "飞龙在天"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int i, count;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FEI "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(FEI "只能空手使用。\n");

        if ((int)me->query_skill("xianglong-zhang", 1) < 450)
                return notify_fail("你降龙十八掌火候不够，难以施展" FEI "。\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("你的内功修为不够，难以施展" FEI "。\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("你的内力修为不够，难以施展" FEI "。\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("你现在的真气不足，难以施展" FEI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "施出降龙十八掌「" HIW "飞龙在天"
              HIY "」，双掌翻滚，宛如一条神龙攀蜒于九天之上"
              "。\n" NOR;  
        ap = me->query("combat_exp", 1);
        dp = target->query("combat_exp", 1);

 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                msg += HIR "$n" HIR "面对$N" HIR "这排山倒海般的攻"
                       "势，完全无法抵挡，招架散乱，连连退后。\n" NOR;
                count = me->query_skill("xianglong-zhang",1) / 20;
        } else
        {
                msg += HIC "$n" HIC "心底微微一惊，心知不妙，急忙"
                       "凝聚心神，竭尽所能化解$N" HIC "数道掌力。\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);

        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 1000);

        for (i = 0; i < 18; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(5) < 2 && ! target->is_busy())
                        target->start_busy(2);

                COMBAT_D->do_attack(me, target, 0, 0);
        }
        me->add("neili", -150);
        me->start_busy(2);
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1000);
        return 1;
}

