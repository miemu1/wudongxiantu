#include <ansi.h>
#include <combat.h>

#define HUI "「" HIR "亢龙有悔" NOR "」"
#define HUIP "「" HIR "亢龙有悔" HIW "」"
string query_name() { return "亢龙有悔"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUI "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUI "只能空手使用。\n");

        if ((int)me->query_skill("force") < 380)
                return notify_fail("你内功修为不够，难以施展" HUI "。\n");

        if ((int)me->query("max_neili") < 6000)
                return notify_fail("你内力修为不够，难以施展" HUI "。\n");

        if ((int)me->query_skill("xianglong-zhang", 1) < 550)
                return notify_fail("你降龙十八掌火候不够，难以施展" HUI "。\n");


        if ((int)me->query("neili") < 1000)
                return notify_fail("你现在真气不够，难以施展" HUI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        // 第一掌
        ap = me->query_skill("xianglong-zhang") + me->query("str") * 5;
        dp = target->query_skill("dodge") + target->query("dex") * 5;

        message_vision(HIW "\n忽然$N" HIW "身形激进，左手一划，右手呼的一掌"
                     "拍向$n" HIW "，正是降龙十八掌" HUIP "。\n力自掌生之际"
                     "说到便到，以排山倒海之势向$n" HIW "狂涌而去，当真石"
                     "破天惊，威力无比。\n" NOR, me, target);

 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                damage = ap + random(ap / 2)+100;
                if (damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage*2,me);
                target->receive_wound("qi", damage,me);
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80,
						HIR "$P身形一闪，竟已晃至$p跟前，$p躲"
                                          "闪不及，顿被击个正中。\n" NOR);
        } else
        {
                msg = HIC "却见$p气贯双臂，凝神应对，$P掌"
                      "力如泥牛入海，尽数卸去。\n" NOR;
        }
        message_vision(msg, me, target);

        // 第二掌
        ap = me->query_skill("xianglong-zhang") + me->query("str") * 5;
        dp = target->query_skill("parry") + target->query("int") * 5;

        message_vision(HIW "\n$N" HIW "一掌既出，身子已然抢到离$n" HIW "三"
                     "四丈之外，后掌推前掌两股掌力道合并，\n又是一招" HUIP
                     "攻出，掌力犹如怒潮狂涌，势不可当。霎时$p便觉气息窒"
                     "滞，立足不稳。\n" NOR, me, target);

 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                damage = ap + random(ap / 2+200);
                if (damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage*2,me);
                target->receive_wound("qi", damage,me);
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 100,
						HIR "$p一声惨嚎，被$P这一掌击中胸前，"
                                          "喀嚓喀嚓断了几根肋骨。"NOR"\n");
        } else
        {
                msg = HIC "可是$p全力抵挡招架，竟似游刃有"
                      "余，将$P的掌力卸于无形。\n" NOR;
        }
        message_vision(msg, me, target);

        // 第三掌
        ap = me->query_skill("xianglong-zhang") + me->query("str") * 5;
        dp = target->query_skill("force") + target->query("con") * 5;

        message_vision(HIW "\n紧跟着$N" HIW "右掌斜挥，前招掌力未消，此招掌"
                     "力又到，竟然又攻出一招" HUIP "，\n掌夹风势，势如破竹，"
                     "便如一堵无形气墙，向前疾冲而去。$n" HIW "只觉气血翻"
                     "涌，气息沉浊。\n" NOR, me, target);

 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                damage = ap + random(ap)+300;
                if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi", damage*2,me);
                target->receive_wound("qi", damage,me);
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 120,
						HIR "结果$p躲闪不及，$P掌劲顿时穿胸而"
                                          "过，顿时口中鲜血狂喷。"NOR"\n");
        } else
        {
                msg = HIC "$p眼见来势凶猛，身形疾退，瞬间"
                      "飘出三丈，脱出掌力之外。\n" NOR;
        }
        message_vision(msg, me, target);
        
                         me->add_temp("apply/attack", 100);
	         me->add_temp("apply/damage", 1000);
	 msg =  HIC  "第一式！$N右掌一式「龙现于野」，勇猛无比地劈向$n！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第二式！$N双掌施出一式「鸿龙在陆」，隐隐约约带着掌风拍向$n！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "第三式！$N左掌御胸，右掌一式「潜龙出海」缓缓推向$n！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "第四式！$N使出「龙跃在天」，向$n的连拍数掌！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "第五式！$N双掌一式「双龙戏水」一前一后按向$n的胸前！" NOR;
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1000);
        
        me->start_busy(2);
        me->add("neili", -200);
        return 1;
}
