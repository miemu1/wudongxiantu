#include <ansi.h>
#include <combat.h>

string query_name() { return "散花"ZJBR"天女"; }

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i, p, n;
        int ap, dp;
        int damage;
        string pmsg;
        string msg;
        object weapon;

        if (playerp(me) && ! me->query("can_perform/tangmen-throwing/san"))
                return notify_fail("你还没有受过高人指点，无法施展。\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("id") != "sanhua tianyu")
                return notify_fail("你现在手中没有拿着暗器散花天女，难以施展。\n");

        if ((skill = me->query_skill("tangmen-throwing", 1)) < 160)
                return notify_fail("你的唐门暗器不够娴熟，难以施展。\n");

        if ((int)me->query_skill("force") < 160)
                return notify_fail("你的内功修为不足，难以施展。\n");

        if ((int)me->query("max_neili") < 1200)
                return notify_fail("你的内力修为不足，难以施展。\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("你现在真气不足，难以施展。\n");

        if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        me->add("neili", -100);

        msg = HIG "$N" HIG "手中扣住一枚" + weapon->name() + "，不理敌人的攻击，身体急速旋转起来，犹如一道呼啸的旋风！\n" NOR
              HIG "突然从旋风中飞出无数点" HIC "寒星" NOR + HIG "，划出一道道长虹闪电般的飞向$n" HIG "的身体！\n" NOR;

        ap = me->query_skill("throwing") + me->query_skill("force");
        dp = target->query_skill("parry") + target->query_skill("dodge") ;

        message_combatd(msg, me, target);
        tell_object(target, HIR "\n你急忙屏气凝神，希望能够招架这致命的一击。\n"NOR);
//        if (ap * 11 / 20 + random(ap / 2) > dp)
        if (ap * 2 / 5 + random(ap * 3 / 5) > dp)
        {
                msg = HIR "忽然那无数的光影一闪而没，$n身行一顿，喷出一口鲜血，仰天而倒。\n" NOR;
                message_combatd(msg, me, target);
                tell_object(target, HIR "你只觉得胸口一阵钻心的疼痛。低头一看只见那无数枚暗器已经深深的嵌在你的心口。\n"
                                    "血迹中隐约有几个小字[散化天雨...]。\n"NOR);
                weapon->hit_ob(me, target, me->query("jiali") + 10000);
                weapon->move(environment(me));

                damage = me->query_skill("throwing") * 2 + me->query_dex()*20 + me->query("jiali")*8 + me->query_skill("暗器百解");
                COMBAT_D->clear_ahinfo();
                //target->die();
                me->start_busy(1);
        } else
        {
                tell_object(target, HIR "忽然那无数的光影一闪而没，你心中一惊急忙运内力于全身。\n" NOR);
                msg = HIR "$n" HIR "双臂急舞，衣袖带起破风之声。只听当的一声轻响，竟将那无数枚暗器磕飞开去。\n" NOR;
                message_combatd(msg, me, target);
                if ( target->query("neili") < 20000 )
                        target->set("neili", 0);
                else
                        target->add("neili", -5000);
                weapon->move(environment(me));
                me->start_busy(4);
        }
        return 1;
}

