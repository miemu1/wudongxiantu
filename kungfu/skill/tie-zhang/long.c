#include <ansi.h>
#include <combat.h>

string name() { return HIR "龙影掌" NOR; }
string query_name() { return "龙影掌"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int level;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail(name() + "只能空手施展。\n");
			
			if(me->query("family/family_name")!="绝情谷")
                return notify_fail("不是绝情谷的不能用使用！\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if ((level = (int)me->query_skill("tie-zhang", 1)) < 100)
                return notify_fail("你铁掌掌法火候不够，难以施展" + name() + "。\n");

        if (me->query_skill_mapped("strike") != "tie-zhang")
                return notify_fail("你没有激发铁掌掌法，难以施展" + name() + "。\n");

        if (me->query_skill_prepared("strike") != "tie-zhang")
                return notify_fail("你没有准备铁掌掌法，难以施展" + name() + "。\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的内功修为不够，难以施展" + name() + "。\n");

        if( me->query("max_neili")<1500 )
                return notify_fail("你的内力修为不够，难以施展" + name() + "。\n");

        if( me->query("neili")<200 )
                return notify_fail("你现在的真气不足，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = WHT "$N" WHT "双掌交错，施出铁掌绝技「" HIR "龙影掌" NOR +
              WHT "」，旋起层层残影，笼罩$n" WHT "四方。\n" NOR;

        ap=me->query_skill("strike")+me->query_str()*15;
        dp=target->query_skill("parry")+target->query_dex()*15;

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "残影晃动间$n" HIR "招式陡然一紧，竟被$N"
                       HIR "的掌招牵引得手忙脚乱！\n" NOR;
                target->start_busy(ap / 80 + 2);
                me->start_busy(1);
                me->add("neili", -100);
        } else
        {
                msg += CYN "可是$n" CYN "看破了$N"
                       CYN "的企图，镇定解招，一丝不乱。\n" NOR;
                me->start_busy(2);
                me->add("neili", -80);
        }
        message_combatd(msg, me, target);

        return 1;
}