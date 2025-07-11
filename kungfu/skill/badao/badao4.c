#include <ansi.h>
#include <combat.h>

#define CHAN "「" HIC "断空" NOR "」"
string query_name() { return "断空"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int level;
        string msg;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHAN "只能对战斗中的对手使用。\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "blade" )
                return notify_fail("你使用的武器不对！\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if ((level = me->query_skill("badao", 1)) < 200)
                return notify_fail("你的开天仙经不够娴熟，难以施展" CHAN "。\n");

        if (me->query_skill_mapped("blade") != "badao")
                return notify_fail("你没有激发开天仙经，难以施展" CHAN "。\n");

        if( me->query("neili")<1000 )
                return notify_fail("你现在真气不够，难以施展" CHAN "。\n");

        if( me->query("qi")<1000 )
                return notify_fail("你现在气血不够，难以施展" CHAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIC "$N" HIC "负刀而立，猛然间，刀锋一转，一股强劲的刀气奔腾而出，瞬间把天空撕裂，将$n" HIC "笼罩。\n" NOR;

        me->add("neili", -1000);
		me->add("qi", -1000);
        if (random(level) + 1000 > (int)target->query_skill("dodge", 1) * 1 / 2)
        {
                msg += HIR "结果$p" HIR "被$P" HIR "闹个手忙脚乱，"
                       "惊慌失措，呆在当场，不知如何应对！\n" NOR;
                target->start_busy(random(3) + 5);
        } else
        {
                msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，镇"
                       "定逾恒，全神应对自如。\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}