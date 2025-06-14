#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define LONG "「" HIY "三千大世界" NOR "」"
string query_name() { return "三千"ZJBR"大世界"; }
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LONG "只能在战斗中对对手使用。\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "blade" )
                return notify_fail("你使用的武器不对！\n");

        if ((int)me->query_skill("badao", 1) < 200)
                return notify_fail("你开天仙经不够娴熟，无法施展" LONG "。\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("你内功火候不够，无法施展" LONG "。\n");

        if( me->query("neili")<1000 )
                return notify_fail("你现在真气不够，无法施展" LONG "！\n");

        if( me->query("qi")<3000 )
                return notify_fail("你的气血不够，无法施展" LONG "！\n");

        if (me->query_skill_mapped("blade") != "badao")
                return notify_fail("你没有激发开天仙经，无法施展" LONG "。\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIC "\n$N" HIC "面露苦色，举手一刀，自上而下，刹那间，天地哭嚎，万千刀气犹如三千个大世界"
              "无可视察，铺天盖地的向前卷进，忽然，无数刀气化为一道刀芒，犹如闪电般劈向$n" HIC "。\n" NOR;

        ap=me->query_skill("blade")*1/3+me->query_skill("martial-cognize",1)*1/2;
        dp=target->query_skill("blade")*1/3+target->query_skill("martial-cognize",1)*1/2;
        if (ap * 5 / 3 + random(ap) > dp)
        {
                me->start_busy(3);
                damage = ap * 1/2 + random(ap * 1/2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 1000 + random(500),
                                           HIR "但见那凶猛无比的刀气势如破竹般的从$n" HIR "胸口透射而过，令人毛骨悚然！\n" NOR);
                me->add("qi", -3000);
				me->add("neili", -1000);
        } else
        {
                me->start_busy(3);
                msg += CYN "然而$n" CYN "轻轻一笑，左避右闪，竟将此招化解。\n" NOR;
                me->add("qi", -10000);
				me->add("neili", -10000);
        }

        message_combatd(sort_msg(msg), me, target);

        return 1;
}
