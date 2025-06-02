#include <ansi.h>
#include <combat.h>

#define ZHUI "��" HIR "�ھ�" NOR "��"
 string query_name() { return "�ھ�"; }
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
                return notify_fail(ZHUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" ZHUI "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹�������ʩչ" ZHUI "��\n");

        if ((int)me->query_skill("longteng-daofa", 1) < 140)
                return notify_fail("������ڵ����������ң�����ʩչ" ZHUI "��\n");

        if (me->query_skill_mapped("blade") != "longteng-daofa")
                return notify_fail("��û�м������ڵ���������ʩչ" ZHUI "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" ZHUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "��Ƿ���а���΢Ц���͵ؼ���ǰ�壬����" + weapon->name() +  
              HIR "����һ���׺磬��ʱһ�������ޱȵ����ε����ƿ�Ϯ��$n" HIR "��\n"NOR;

        ap = me->query_skill("blade");
        dp = target->query_skill("parry");     
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("blade");
                me->add("neili", -150);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
                                           HIR "ֻ��$n" HIR "һ���ҽУ�����������"
                                           "������������ģ�������Ѫ���������\n" NOR);
                me->start_busy(2);
        } else 
        {
                msg += CYN "����$p" CYN "Ĭ��������Ӳ�ǵֵ���$P"
                       CYN "��������ε�����\n"NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

