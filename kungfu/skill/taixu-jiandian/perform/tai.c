// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#define TAI "「" HIC "太虚剑气" NOR "」"
string query_name() { return "太虚"ZJBR"剑气"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
		object weapon;
        int ap, dp;
        int count;
        int i;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

     

        if (! target || ! me->is_fighting(target))
                return notify_fail(TAI "只能对战斗中的对手使用。\n");

        /* if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(TAI "只能空手施展。\n"); */

        if (me->query("max_neili") < 6000)
                return notify_fail("你的内力的修为不够，现在无法使用" TAI "。\n");

        if (me->query_skill("taixu-jiandian", 1) < 200)
                return notify_fail("你的太虚剑气还不够娴熟，难以施展" TAI "。\n");

        if (me->query_skill_mapped("unarmed") != "taixu-jiandian")
                return notify_fail("你现在没有激发太虚剑气为拳脚，难以施展" TAI "。\n");

        if (me->query_skill_mapped("force") != "taixu-jiandian")
                return notify_fail("你现在没有激发太虚剑气为内功，难以施展" TAI "。\n");
			
		if (me->query_skill_mapped("sword") != "taixu-jiandian")
                return notify_fail("你现在没有激发太虚剑气为剑法，难以施展" TAI "。\n");

        if (me->query_skill_prepared("unarmed") != "taixu-jiandian")
                return notify_fail("你现在没有准备使用太虚剑气，难以施展" TAI "。\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("你的真气不够，无法运用" TAI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIC "$N" HIC "以剑心御气，顿时一股浩荡无比的剑气至体内迸发，双手内息"
              "化为剑气，朝$n" HIC "四散而去。\n" NOR;

        ap = me->query_skill("sword")+ me->query("int")*20;
        dp = target->query_skill("parry")+me->query("con")*20;

        if (ap / 2 + random(ap) > dp)
        {
                count = ap;
                msg += HIC "$n" HIC "只觉周围肌肤刺痛无比，又见无数剑气向"
                       "自己袭来，内心慌乱无比，不知该如何抵挡。\n" NOR;
        } else
        {
                msg += HIY "$n" HIY "只见$N" HIY "无数剑气向自己袭来，连"
                       "忙就地一滚，勉强躲开。\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);
        me->add_temp("apply/attack", count);
        me->add_temp("apply/unarmed_damage", count/3);
		me->add_temp("apply/damage", count/3);

        me->add("neili", -300);

        for (i = 0; i < 12; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(5) < 2 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->start_busy(1 + random(3));
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/unarmed_damage", -(count/3));
		me->add_temp("apply/damage", -(count/3));

        return 1;
}

