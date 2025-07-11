#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIR "逍遥" + HIY + "醉心" + HIR "剑" NOR; }
string query_name() { return "逍遥"ZJBR"醉心剑"; }
int perform(object me, object target)
{
        string type1, type2, msg;
        object weapon1, weapon2, weapon;
        int ap, dp, damage;
        int fmsk = me->query_skill("beiming-shengong", 1);
        int da_add;
        int i, count;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");
        
        if( me->is_busy() )
                return notify_fail("你正忙着呢。\n");
       

        if ( (string)me->query("family/family_name") != "逍遥派") 
     return notify_fail("只有逍遥弟子才能使用该PFM。\n");
		if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
		if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");

        if (me->query_skill_mapped("sword") != "zuixin-sword")
                return notify_fail("你没有激发逍遥醉心剑，难以施展" + name() + "。\n");

        if (me->query_skill("zuixin-sword", 1) < 500)
                return notify_fail("你的剑归真等级不够，难以施展" + name() + "。\n");

        if (me->query("neili") < 2000)
                return notify_fail("你现在的真气不够，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
		
		fmsk = me->query_skill("daojian-xiaotianwai", 1);
        ap = me->query_skill("sword", 1) + me->query_skill("martial-cognize", 1);
        dp = target->query_skill("force", 1)+ me->query_skill("martial-cognize", 1);

        damage = ap;
        damage+= me->query_skill("sword", 1);
        damage+= me->query("jiali");

        msg = HIY "$N" HIY "将 手中宝剑横置于胸前，运转出" + name() + HIY "那一刻天地变换。\n" NOR;

        msg += HIY "那是天下的剑" HIY "$N" HIY "仿若与这剑融为一体，\n"
                   "只是瞬间手中宝剑剑光转瞬即逝\n"
                   HIY"$N" HIY "身前的一切均化做剑光\n"
                   "以无敌之势射像"HIY "$n"HIY"。\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "哪里见过$N" HIR "这样的气势，这样的武功，不禁心"
                       "生惧意，招架顿时散乱，全然不成章理。\n" NOR;

                target->receive_damage("jing", damage / 2);
                target->receive_wound("jing", damage / 3);

                msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 100,
                                           HIR "$n" HIR " 一时竟不知抵挡"
                                           "，被$N" HIR "一剑刺中受"
                                           "伤不轻。\n" NOR);
                ap += ap / 5;
                damage += damage / 3;
        } else
        {
                msg += HIG "$n" HIG "见$N" HIG "武功稀奇，丝毫不"
                       "敢大意，急忙收敛心神。\n" NOR;
        }

        msg += HIW "\n突然间$N" HIW "身形一幻，右手" + weapon->name() +
               HIW "化作一道流光\n" NOR;

        if (me->query_skill("count", 1) > 300)
        {
                damage = damage + damage / 3;
                da_add = (80 + fmsk / 15) + (80 + fmsk / 15) / 3;
        }

        if (ap / 2 + random(ap) > dp)
        {

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, da_add,
                                           HIR "$n" HIR "奋力抵挡，却根本无法招架"
                                           "，被$N" HIR "一剑刺入心脉，鲜血四处飞"
                                           "溅。\n" NOR);
        } else
        {
                msg += CYN "$n" CYN "明白这一剑的强大，急忙凝神"
                       "聚气，小心拆招。\n" NOR;
        }

        msg += HIW "\n接着$N" HIW "又将右手" + weapon->name() +
               HIW "立于胸前，剑气肆意，无可阻拦，"
               "那是天上的剑。\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                /*
                weapon1->move(me, 1);
                weapon2->wield();
                */

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, da_add,
                                           HIR "$n" HIR "只觉眼花缭乱，全然无法洞"
                                           "察先机，$N" HIR "一招命中，射出一柱鲜"
                                           "血。\n" NOR);
                /*
                weapon2->move(me, 1);
                weapon1->wield();
                set_temp("handing", weapon2, me);
                */
        } else
        {
                msg += CYN "$n" CYN "心知这一招的凌厉，急忙凝神"
                       "聚气，小心拆招，丝毫无损。\n" NOR;
        }
        if( me->query("family/family_name") == "逍遥派"&& fmsk >= 100 && me->query("neili")>1000)
        {
                msg += HIC "\n====================" HIY" 逍" HIR "  遥" HIG "  醉" HIW " 心剑" HIC " ====================" NOR;
                msg += HIC "\n猛然间，$N" HIC "手中" + weapon->name()  + HIC +
                           "发出阵阵清音，化作一道流光，飞向$n" HIC "。\n" NOR;

                if (ap / 2 + random(ap)  + fmsk / 2 > dp)
                {
                        damage *= 2;
                        msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 350,
                                           HIR "$n" HIR "刹那间目瞪口呆，全然无法相信"
                                           "眼前之景象，$N" HIR "一招命中，射出两柱鲜"
                                           "血。\n" NOR);
                        me->add("neili", -500);
                        
                        count = me->query_skill("martial-cognize", 1) + me->query_skill("sword-cognize", 1);
                        count /= 1000;
                        if (! target->is_busy())
                                target->start_busy(8 + random(count));
                        
                        target->set_weak(3 + random(count));
                } else
                {
                        msg += CYN "$n" CYN "丝毫不被眼前景象所影响，从容闪躲，避开这一招。\n" NOR;
                }
        }
        
        count = 0;
        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIW "$n" HIW "只见无数剑光向自己袭来，慌的一批。\n" NOR;
                count = ap / 15;
                me->set_temp("xiaoyao/max_pfm", 1);
        } else
        {
                msg += HIG "$n" HIG "突然发现自己四周皆被剑光所包围，急忙小心防备。\n" NOR;
                count = ap / 30;
        }
        message_combatd(msg, me, target);
        
        me->add("neili", -500);
        me->add_temp("apply/attack", count);
        me->add_temp("apply/damage", count*2/3);
        me->add_temp("apply/avoid_locked", 50);
        for (i = 0; i < 12; i++)
        {
                if (! me->is_fighting(target))
                        break;

                COMBAT_D->do_attack(me, target, weapon, 100);
        }
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count*2/3);
        me->add_temp("apply/avoid_locked", -50);
        me->delete_temp("xiaoyao/max_pfm"); 
        me->start_busy(3 + random(2));
        
        message_combatd(msg, me, target);
        return 1;
}
