#include <ansi.h>

inherit F_SSERVER;

#define LIAN "「" HIW "天下无敌" NOR "」"
 string query_name() { return "天下"ZJBR"无敌"; }
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;
        int count;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "只能对战斗中的对手使用。\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "blade" )
                return notify_fail("你使用的武器不对！\n");

        if( me->query("neili")<5000 )
                return notify_fail("你的真气不够，无法施展" LIAN "！\n");

        if( me->query("qi")<2000 )
                return notify_fail("你的气血不够，无法施展" LIAN "！\n");

        if ((int)me->query_skill("force") < 600)
                return notify_fail("你的内功火候不够，难以施展" LIAN "！\n");

        if ((int)me->query_skill("badao", 1) < 600)
                return notify_fail("你的开天仙经还不到家，无法施展" LIAN "！\n");

        if (me->query_skill_mapped("blade") != "badao")
                return notify_fail("你没有激发开天仙经，无法施展" LIAN "。\n");

        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "使出失传已久的开天仙经绝技「" HIW "天下无敌" HIY"」，刀法陡然加快，眨眼间，八刀劈出 ……\n" NOR;

        message_combatd(msg, me);
        me->add("neili", -5000);
		me->add("qi", -2000);

        count = me->query_skill("blade") * 13 / 3;
        me->add_temp("apply/damage", count);

        for (i = 0; i < 8; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/damage", -count);
        me->start_busy(2 + random(3));
        return 1;
}