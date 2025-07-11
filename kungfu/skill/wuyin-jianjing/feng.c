#include <ansi.h>
#include <combat.h>

#define FENG "「" HIW "诸神避退" NOR "」"
string query_name() { return "诸神避退"; }
string name() { return HIR "诸神避退" NOR; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, wn;
        object weapon;
        int level;

      /*   if( userp(me) && !me->query("can_perform/wuyin-jianjing/feng") )
                return notify_fail("你所使用的外功中没有这种功能。\n"); */

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FENG "只能对战斗中的对手使用。\n");

        if( !objectp(weapon=me->query_temp("weapon") )
            || weapon->query("skill_type") != "sword" )
                return notify_fail("你使用的武器不对，难以施展" FENG "。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if ((int)me->query_skill("wuyin-jianjing", 1) < 100)
                return notify_fail("你无垠剑经不够娴熟，难以施展" FENG "。\n");

        if (me->query_skill_mapped("sword") != "wuyin-jianjing")
                return notify_fail("你没有激发无垠剑经，难以施展" FENG "。\n");

        if (me->query_skill("dodge") < 600)
                return notify_fail("你的轻功修为不够，难以施展" FENG "。\n");

        if( me->query("neili")<1500 )
                return notify_fail("你现在的真气不够，难以施展" FENG "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        wn = weapon->name();

        msg = HIC "\n$N" HIC "将" + wn + HIC "横于胸前，内力贯于剑身，"
              "猛然间" + wn + HIC "如一条长龙般挥出，霎时狂沙满天，令"
              "人匪夷所思。" NOR;

        message_sort(msg, me, target);

        level = me->query_skill("sword");

        me->add("neili", -1500);

        if (level * 1 / 3 + random(level) > target->query_skill("dodge"))
        {
                msg = HIY "$N" HIY "看不出$n" HIY "招式中的虚实，连忙"
                      "护住自己全身，一时竟无以应对！\n" NOR;
                target->start_busy(1 + random(level / 200));
                me->start_busy(random(2));
        } else
        {
                msg = CYN "可是$N" CYN "镇定自若，小心拆招，没有被"
                      "$n" NOR + CYN "招式所困。\n" NOR;

                me->start_busy(2);
        }
        message_combatd(msg, target, me);

        return 1;
}