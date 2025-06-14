#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return "天脉神剑"; }
string query_name() { return "天脉"ZJBR"神剑"; }
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage, skill;
        int n;

        if (! target) target = offensive_target(me);

      if( me->query("family/family_name") != "段氏皇族"  ) 
               // return notify_fail("你所使用的外功中没有这种功能。\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if( me->is_busy() )
                return notify_fail("你正忙着呢。\n");

        if (me->query_skill_prepared("finger") != "six-finger")
                return notify_fail("你没有准备使用六脉神剑，无法施展" + name() + "。\n");

        skill = me->query_skill("six-finger", 1);

        if (skill < 800)
                return notify_fail("你的六脉神剑修为有限，无法使用" + name() + "！\n");

        if (me->query_skill("force", 1) < 800)
                return notify_fail("你的内功火候不够，难以施展" + name() + "！\n");

        if( me->query("max_neili")<12000 )
                return notify_fail("你的内力修为不够,无法施展" + name() + "！\n");

        if( me->query("neili")<1000 )
                return notify_fail("你的真气不够，现在无法施展" + name() + "！\n");

        if( me->query_temp("weapon") )
                return notify_fail("你必须是空手才能施展" + name() + "！\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");


        msg = HIM "$N" HIM "一声清啸，右手五指纷弹，顿觉六脉剑谱已涌上心头，此起"
              "彼伏、连绵不绝。\n霎时剑气如奔，连绵无尽的万道剑气豁然贯向$n" HIM
              "！\n" NOR;

        ap = me->query_skill("finger");
        dp = target->query_skill("force");

        // 提高20%
        ap = ap + ap / 5 + me->query_skill("martial-cognize", 1) + me->query_skill("jingluo-xue", 1);

        // 有20%几率施展无BUSY
        if (random(5) != 1) me->start_busy(2 + random(3));

        if ((int)target->query_skill("martial-cognize", 1) >= 2000
            && target->query_skill("dodge", 1) >= me->query_skill("six-finger", 1)
            && random (10) == 1 )
        {
                me->add("neili", -2000);
                msg += HIY "但见$n" HIY "会心一笑，轻拂衣袖，轻易的躲过这一招！\n"NOR;
        } else
        if (ap + random(ap) > dp)
        {
                damage = me->query_skill("finger") + me->query_skill("martial-cognize", 1) + me->query_skill("jingluo-xue", 1);
                damage *= 3;
                if( (n = me->query_skill("qimai-liuzhuan", 1) / 100) >= 1 )
                {
                        damage += damage*n*15/100;
                        msg += HIM"$N"HIM"运用气脉流转的辅助，使得天脉神剑伤害更强。\n"NOR;
                }

                me->add("neili", -1800);
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 300 + random(200),
                                           HIR "只听$n" HIR "一声惨叫，万道剑气已"
                                           "透体而过，伤口处鲜血顿时狂涌，痛苦难当！\n" NOR);
                target->set_weak(5);
                if( !target->is_busy() ) target->start_busy(8);
        } else
        {
                me->add("neili", -400);
                msg += CYN "$n" CYN "见$N" CYN "来势汹涌，不敢轻易"
                       "招架，急忙提气跃开。\n" NOR;
        }

        msg += HIG "\n紧接着，$N" HIG "一声清啸，左手五指纷弹，顿觉六脉剑谱已涌上心头，此起"
              "彼伏、连绵不绝。\n霎时剑气如奔，连绵无尽的万道剑气豁然贯向$n" HIG
              "！\n" NOR;

        // 再发一招
        if ((int)target->query_skill("martial-cognize", 1) >= 2000
            && target->query_skill("dodge", 1) >= me->query_skill("six-finger", 1)
            && random (10) == 1 )
        {
                me->add("neili", -600);
                msg += HIY "但见$n" HIY "会心一笑，轻拂衣袖，轻易的躲过这一招！\n"NOR;
        } else
        if (ap + random(ap) > dp)
        {
                damage = me->query_skill("finger") * 3;
                if( (n = me->query_skill("qimai-liuzhuan", 1) / 100) >= 1 )
                {
                        damage += damage*n*15/100;
                        msg += HIM"$N"HIM"运用气脉流转的辅助，使得天脉神剑伤害更强。\n"NOR;
                }

                me->add("neili", -800);
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 300 + random(200),
                                           HIR "只听$n" HIR "一声惨叫，万道剑气已"
                                           "透体而过，伤口处鲜血顿时狂涌，痛苦难当！\n" NOR);
                target->set_weak(5);
                if( !target->is_busy() ) target->start_busy(8);
        } else
        {
                me->add("neili", -400);
                if (random(5) != 1)me->start_busy(5);
                msg += CYN "$n" CYN "见$N" CYN "来势汹涌，不敢轻易"
                       "招架，急忙提气跃开。\n" NOR;
        }
        message_combatd(msg, me, target);


        return 1;
}
