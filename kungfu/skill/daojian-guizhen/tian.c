#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int fmsk = this_player()->query_skill("daojian-xiaotianwai", 1);
//string name() { return HIR "刀剑" + HIY + chinese_number(7 + fmsk / 100) + HIR "重天" NOR; }
string name() { return HIR "刀剑" + HIY + "七" + HIR "重天" NOR; }
string query_name() { return "刀剑"ZJBR"七重天"; }
int perform(object me, object target)
{
        string type1, type2, msg;
        object weapon1, weapon2;
        int ap, dp, damage;
        //int fmsk = me->query_skill("daojian-xiaotianwai", 1);
        int da_add;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        weapon1 = me->query_temp("weapon");
        weapon2 = me->query_temp("secondary_weapon") || me->query_temp("handing");

        if (! objectp(weapon1) || ! objectp(weapon2))
                return notify_fail("你没有同时装备刀剑，难以施展" + name() + "。\n");

        if (weapon2->query("consistence") <= 0)
                return notify_fail("你的" + weapon2->name() + "已经严重"
                                   "损坏，无法继续使用了。\n");

        type1 = weapon1->query("skill_type");
        type2 = weapon2->query("skill_type");
		

	
        if ((type1 != "sword" && type1 != "blade")
           || (type2 != "sword" && type2 != "blade"))
                return notify_fail("你所使用的武器不对，难以施展" + name() + "。\n");

        if ((type1 == "sword" && type2 != "blade")
           || (type1 == "blade" && type2 != "sword"))
                return notify_fail("你没有同时装备刀剑，难以施展" + name() + "。\n");

        if (me->query_skill_mapped("sword") != "daojian-guizhen"
           || me->query_skill_mapped("blade") != "daojian-guizhen")
                return notify_fail("你没有激发刀剑归真，难以施展" + name() + "。\n");

        if (me->query_skill("daojian-guizhen", 1) < 250)
                return notify_fail("你的剑归真等级不够，难以施展" + name() + "。\n");

        if (me->query("neili") < 1000)
                return notify_fail("你现在的真气不够，难以施展" + name() + "。\n");
			if( me->query_skill("lengyue-shengong")<500 )
                return notify_fail("你现在的内功不够，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        fmsk = me->query_skill("daojian-xiaotianwai", 1);
        ap = me->query_skill("blade", 1) ;
        dp = target->query_skill("force", 1);

        damage = me->query_skill("blade", 1) ;
        damage+= me->query_skill("sword", 1) ;
        damage+= me->query("jiali");
    //    damage*=3;

        msg = HIY "$N" HIY "将" + weapon1->name() + HIY "与" +
              weapon2->name() + HIY "横置于胸前，运转出" + name() + HIY "功力，内劲如海啸般爆发。\n" NOR;

        msg += HIY "空气、云都变成了暗红色，整个天地灵气，一草一木上散发出来的生机，包括" HIY "$N" HIY "强大的杀气、刀魂、剑意，\n"
                   "在瞬间全部凝聚在了一起，随着手中" + weapon1->name() + HIY "和" + weapon2->name() + HIY "的共鸣，所有阻挡在\n"
                   HIY"$N" HIY "面前的东西，好像全部在一瞬间被击碎，迫开。整个天空，似乎被斩成了两半，捅出了一个窟窿。\n"
                   "这一人、一刀、一剑毫不留情的，狠狠的飞向了"HIY "$n"HIY"。\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "哪里见过$N" HIR "这样的气势，这样的武功，不禁心"
                       "生惧意，招架顿时散乱，全然不成章理。\n" NOR;

                target->receive_damage("jing", damage / 2);
                target->receive_wound("jing", damage / 3);

                msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 100,
                                           HIR "$n" HIR "失魂落魄， 一时竟不知抵挡"
                                           "，被$N" HIR "一剑刺中要害，鲜血四溅受"
                                           "伤不轻。\n" NOR);
                ap += ap / 5;
                damage += damage / 3;
        } else
        {
                msg += HIG "$n" HIG "见$N" HIG "杀气大涨，丝毫不"
                       "敢大意，急忙收敛心神，努力不受干扰。\n" NOR;
        }

        msg += HIW "\n突然间$N" HIW "身形一展，右手" + weapon1->name() +
               HIW "忽地一振，凌空卷出一道半弧，直劈$n" HIW "而去。\n" NOR;

        if (me->query_skill("zuoyou-hubo", 1) > 200)
        {
                damage = damage + damage / 3;
                da_add = (100 + fmsk / 15) + (100 + fmsk / 15) / 2;
        }

        if (ap / 2 + random(ap) > dp)
        {

                msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, da_add,
                                           HIR "$n" HIR "奋力抵挡，却哪里招架得住"
                                           "，被$N" HIR "一招划中要脉，鲜血四处飞"
                                           "溅。\n" NOR);
        } else
        {
                msg += CYN "$n" CYN "心知这一招的凌厉，急忙凝神"
                       "聚气，小心拆招，丝毫无损。\n" NOR;
        }

        msg += HIW "\n接着$N" HIW "又将左手" + weapon2->name() +
               HIW "朝$n" HIW "平平递出，招式看似简单，却蕴藏着"
               "极大的杀着。\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                /*
                weapon1->move(me, 1);
                weapon2->wield();
                */

                msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, da_add,
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

        if( me->query("family/family_name") == "关外胡家" || me->query("family/family_name") == "中原苗家" && fmsk >= 100 && me->query("neili")>1000)
        {
                msg += HIC "\n====================" HIY" 刀" HIR "  剑" HIG "  啸" HIW "  天  外" HIC " ====================" NOR;
                msg += HIC "\n猛然间，$N" HIC "手中" + weapon1->name() + HIC "和" + weapon2->name() + HIC +
                           "发出震天般的长啸，伴随着两道光华飞至天际，但见天云突变，\n转眼间，数道金光从天边划过，飞向$n" HIC "。\n" NOR;

                if (ap / 2 + random(ap)  + fmsk > dp)
                {
                        msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 350,
                                           HIR "$n" HIR "刹那间目瞪口呆，全然无法相信"
                                           "眼前之景象，$N" HIR "一招命中，射出两柱鲜"
                                           "血。\n" NOR);
                        me->add("neili", -500);
                        if (! target->is_busy())
                                target->start_busy(3 + random(3));
                } else
                {
                        msg += CYN "$n" CYN "丝毫不被眼前景象所影响，从容闪躲，避开这一招。\n" NOR;
                }
        }

        me->start_busy(2 + random(3));
        me->add("neili", -500);
        message_combatd(msg, me, target);
        return 1;
}
