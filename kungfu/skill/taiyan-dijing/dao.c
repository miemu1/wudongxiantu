#include <ansi.h>

inherit F_SSERVER;

#define LIAN "「" HIW "归墟十二刀" NOR "」"
 string query_name() { return "归墟"ZJBR"十二刀"; }
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

        if( me->query("neili")<12000 )
                return notify_fail("你的真气不够，无法施展" LIAN "！\n");
			
			        if( me->query("qi")<1200 )
                return notify_fail("你的气血不够，无法施展" LIAN "！\n");

        if ((int)me->query_skill("blade", 1) < 600)
                return notify_fail("你的基础刀法还修炼不到家，无法施展" LIAN "！\n");

        if ((int)me->query_skill("force", 1) < 600)
                return notify_fail("你的基础内功还修炼不到家，无法施展" LIAN "！\n");

        if ((int)me->query_skill("taiyan-dijing", 1) < 600)
                return notify_fail("你的太衍帝经还修炼不到家，无法施展" LIAN "！\n");

        if (me->query_skill_mapped("blade") != "taiyan-dijing")
                return notify_fail("你没有激发太衍帝经，无法施展" LIAN "。\n");

        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "使出太衍帝经的绝技「" HIW "归墟十二刀" HIY"」，刀法陡然加快，眨眼间，劈出了十二刀。\n" NOR;

        message_combatd(msg, me);
        me->add("neili", -12000);
		me->add("qi", -1200);

        count = me->query_skill("blade") * 8 / 3;
        me->add_temp("apply/damage", count);

        for (i = 0; i < 12; i++)
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