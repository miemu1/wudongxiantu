#include <ansi.h>
#include <combat.h>

#define XIAN "��" HIY "��ʱ������" NOR "��"
string query_name() { return "��ʱ"ZJBR"������"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" XIAN "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" XIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");
        
        msg = HIY "$N" HIY "������գ�����˸���������ߵ���ÿ������$n" HIY "���ò�ȫ��Ӧ����\n"
              "ÿ��������ʵ��׾��ƫ���У����µ��յĸо���\n"
              "�ҵ��������$n" HIY "�����α仯�����ǰ�$n" HIY "��ͨ��͸һ�㣡\n" NOR;
        
        ap = ap = me->query_skill("force") + me->query_skill("blade");
        dp = target->query_skill("dodge") + target->query_skill("force");
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("blade");
                damage *= 3;
                me->add("neili", -150);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 95,
                                           HIR "��ʱһ�ɱ����ĵ����ӹ�ȫ��$n" 
                                           HIR "ȫ���ʱ��Ѫ���죬ҡҡ������\n" NOR);
                me->start_busy(2);
                if (ap / 2 + random(ap * 2) > dp && ! target->is_busy())
                        target->start_busy(ap / 100 + 3);
        } else 
        {
                msg += CYN "$p" CYN "���һ����Ҳ���мܣ��������"
                       "�������ߣ��ܿ���$P" CYN "��һ�С�\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}


