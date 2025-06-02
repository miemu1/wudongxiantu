#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define JIU "��" HIW "��������" NOR "��"

string query_name() { return "����"ZJBR"����"; }

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        string msg;
        int count;
        int lvl, damage;
        int i, ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query("neili") < 5000)
                return notify_fail("��������������޷�ʩչ" JIU "��\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("������������������ʹ��" JIU "��\n");
			
        if ((int)me->query("qi") < 1000)
                return notify_fail("�����Ѫ�������޷�ʩչ" JIU "��\n");

        if (me->query("max_qi") < 1000)
                return notify_fail("��������Ѫ��������ʹ��" JIU "��\n");			

        if ((int)me->query_skill("force") < 600)
                return notify_fail("����ڹ���򲻹�������ʩչ" JIU "��\n");

        if ((int)me->query_skill("sword") < 600)
                return notify_fail("��Ľ�����򲻹�������ʩչ" JIU "��\n");

        if ((lvl = (int)me->query_skill("wushang-jianjing", 1)) < 600)
                return notify_fail("������Ͻ����������������޷�ʹ��" JIU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        message_sort(HIM "\n$N" HIM "�������Ͻ�������ؼ�����·�Ի������У�"
                     HIM "�������Ͻ��޾�ѧ" JIU HIM "��\n" NOR, me, target);

        ap = me->query_skill("sword") * 3 + me->query_skill("wushang-jianjing", 1) + me->query_skill("sword-cognize", 1);
        dp = target->query_skill("dodge") + target->query_skill("sword-cognize");

        for (i = 0; i < 9; i++)
        {
                if (! me->is_fighting(target))
                        break;

                message_sort(HIW "\n$N" HIW "����������Ю����֮�����ӿ�����$n"
                             HIW "����������\n" NOR, me, target);

                if (ap * 8 / 2 + random(ap) > dp)
                {
                        damage = me->query_skill("sword") * 17 ;
                        if (me->query_temp("weapon"))
                        {
                                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, (i + 1) * 7,
                                                          HIR "���$n" HIR "����������$N" HIR
                                                          "�Ľ�����������룬$n��ͷһ�����һ��"
                                                          "����Ѫ��\n" NOR);
                        } else
                        {
                                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, (i + 1) * 7,
                                                          HIR "���$n" HIR "����������$N" HIR
                                                          "�Ľ�����������룬$n��ͷһ�����һ��"
                                                          "����Ѫ��\n" NOR);
                        }
                } else
                {
                        msg = CYN "$n" CYN "����˫�ۣ������мܣ���"
                              "$N" CYN "���ھ�ж����\n" NOR;
                }

                message_sort(msg, me, target);

                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(1);
        }

        me->start_busy(6 + random(1));
        me->add("neili", -4500 - random(500));
        me->add("qi", -500 - random(500));
        return 1;
}


