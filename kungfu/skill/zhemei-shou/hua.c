// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

string name() { return HIR "化妖功" NOR; }
string query_name() { return "化妖功"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp, p;
        int lv, cost_neili;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail(name() + "只能空手施展。\n");
		
		if(me->query("family/family_name")!="逍遥派")
                return notify_fail("不是逍遥派的不能用化妖功！\n");


        if (lv = (int)me->query_skill("zhemei-shou", 1) < 220)
                return notify_fail("你折梅手等级不够，难以施展" + name() + "。\n");

        if( me->query("max_neili")<4000 )
                return notify_fail("你的内力修为不足，难以施展" + name() + "。\n");

        if( me->query("neili")<800 )
                return notify_fail("你现在真气不足，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIM "$N" HIM "深深吸进一口气，单手挥出，掌缘顿时霞光万道，漾出"
              "七色虹彩向$n" HIM "席卷而至。\n" NOR;

        ap = me->query_skill("hand") + me->query_skill("dodge");
        dp = target->query_skill("parry") + target->query_skill("dodge");

        if (target->is_bad() || ! userp(target))
                ap += ap / 10;

        if (ap / 2 + random(ap) > dp)
        {
                damage = 0;
                lv = me->query_skill("zhemei-shou", 1);
                if (lv >= 220)cost_neili = -500;
                if (lv >= 240)cost_neili = -470;
                if (lv >= 260)cost_neili = -440;
                if (lv >= 280)cost_neili = -400;
                if (lv >= 300)cost_neili = -360;
                if (lv >= 320)cost_neili = -320;
                if (lv >= 340)cost_neili = -300;
                if (lv >= 360)cost_neili = -270;
                if (lv >= 400)cost_neili = -200;
                if( me->query("max_neili")>target->query("max_neili")*2 )
                {
                        msg += HIM "只听$n" HIM "一声尖啸，$N" HIM "的七色掌"
                               "劲已尽数注入$p" HIM "体内，顿时将$p" HIM "化"
                               "为一滩血水。\n" NOR "( $n" RED "受伤过重，已"
                               "经有如风中残烛，随时都可能断气。" NOR ")\n";
                        damage = -1;
                        me->add("neili", cost_neili);
                        me->start_busy(1);
                } else
                {
                        damage = me->query_skill("hand");
                        damage+=me->query("jiali");
                        damage*=2;

                        target->receive_damage("qi", damage, me);
                        target->receive_wound("qi", damage / 2, me);
                        target->receive_damage("jing", damage / 4, me);
                        target->receive_wound("jing", damage / 8, me);
                        p=target->query("qi")*100/target->query("max_qi");

                        msg += HIM "$n" HIM "只是微微一愣，$N" HIM "的七色掌劲已破体而"
                               "入，$p" HIM "便犹如身置洪炉一般，连呕数口鲜血。\n" NOR;
                        msg += "( $n" + eff_status_msg(p) + " )\n";

                        me->add("neili", cost_neili);
                        me->start_busy(3);
                }
        } else
        {
                msg += CYN "$p" CYN "见状大惊失色，完全勘破不透$P"
                       CYN "招中奥秘，当即飞身跃起丈许，躲闪开来。\n" NOR;
                me->add("neili", -200);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        if (damage < 0)
        {
                target->receive_damage("qi", 100, me);
               // target->unconcious(me);
        }

        return 1;
}