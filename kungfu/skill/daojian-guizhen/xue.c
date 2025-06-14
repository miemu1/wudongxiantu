// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

string name() { return HIW "天下有" HIR "血" NOR; }
string query_name() { return "天下"ZJBR"有血"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string type1, type2, msg;
        object weapon1, weapon2;
        int i, count, damage;
        int ap, dp;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        weapon1 = me->query_temp("weapon");
        weapon2 = me->query_temp("secondary_weapon") || me->query_temp("handing");

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

        if( me->query("neili")<500 )
                return notify_fail("你现在的真气不够，难以施展" + name() + "。\n");
			if( me->query_skill("lengyue-shengong")<500 )
                return notify_fail("你现在的内功不够，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "手中" + weapon1->name() + HIW "蓦地一抖"
              "，将「" NOR + WHT "胡家刀法" HIW "」并「" NOR + WHT
              "苗家剑法" HIW "」连环施出。霎时寒\n光点点，犹如夜陨"
              "划空，铺天盖地罩向$n" HIW "，正是一招「" HIW "天下"
              "有" HIR "血" HIW "」。\n" NOR;

        ap = me->query_skill("blade", 1) ;
        dp = target->query_skill("parry", 1);

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIW "$n" HIW "只见无数刀光剑影向自己逼"
                       "来，顿感眼花缭乱，心底寒意油然而生。\n" NOR;
                count = ap / 15;
                me->set_temp("daojian-guizhen/max_pfm", 1);
        } else
        {
                msg += HIG "$n" HIG "突然发现自己四周皆被刀光"
                       "剑影所包围，心知不妙，急忙小心招架。\n" NOR;
                count = ap / 30;
        }
        message_combatd(msg, me, target);

        me->add("neili", -300);
        me->add_temp("apply/attack", count);
        me->add_temp("apply/damage", count*2/3);

        for (i = 0; i < 12; i++)
        {
                if (! me->is_fighting(target))
                        break;

                COMBAT_D->do_attack(me, target, (random(2) ? weapon1:weapon2), 100);
        }
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count*2/3);
        me->delete_temp("daojian-guizhen/max_pfm");
        me->start_busy(2 + random(2));
        return 1;
}
