#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define JIU "「" HIW "仙法·游龙惊雷" NOR "」"

string query_name() { return "[仙法]"ZJBR"游龙惊雷"; }

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        string msg;
        int count;
        int lvl, damage;
        int i, ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIU "只能对战斗中的对手使用。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        message_sort(HIM "\n$N" HIM "运起修仙真法，仿佛九天神龙翱翔天际，"
                     HIM "正是无上绝学" JIU HIM "！\n" NOR, me, target);

        ap = me->query_skill("cuff") + me->query_skill("xiuxian-gongfas", 1) + me->query_skill("xiuxian-gongfas", 1);
        dp = target->query_skill("dodge") + target->query_skill("parry");

        for (i = 0; i < 3; i++)
        {
                if (! me->is_fighting(target))
                        break;

                message_sort(HIW "\n$N" HIW "身若游龙，挟风雷之力，从空中向$n"
                             HIW "猛扑下来！\n" NOR, me, target);

                if (ap * 25 / 2 + random(ap) > dp)
                {
                        damage = me->query_skill("cuff");
                        if (me->query_temp("weapon"))
                        {
                                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, (i + 1) * 35 ,
                                                          HIR "结果$n" HIR "躲闪不及，$N" HIR
                                                          "的内劲已破体而入，$n喉头一甜，喷出一大"
                                                          "口鲜血。\n" NOR);
                        } else
                        {
                                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, (i + 1) * 35,
                                                          HIR "结果$n" HIR "躲闪不及，$N" HIR
                                                          "的内劲已破体而入，$n喉头一甜，喷出一大"
                                                          "口鲜血。\n" NOR);
                        }
                } else
                {
                        msg = CYN "$n" CYN "气凝双臂，奋力招架，将"
                              "$N" CYN "的内劲卸掉。\n" NOR;
                }

                message_sort(msg, me, target);

                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(1);
        }

        me->start_busy(1 + random(1));
        me->add("neili", -1 - random(1000));
        return 1;
}


