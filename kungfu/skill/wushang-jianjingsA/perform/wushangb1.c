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

        if ((int)me->query("neili") < 3000)
                return notify_fail("��������������޷�ʩչ" JIU "��\n");

        if (me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ��������ʹ��" JIU "��\n");

        if ((int)me->query_skill("force") < 600)
                return notify_fail("����ڹ���򲻹�������ʩչ" JIU "��\n");

        if ((int)me->query_skill("sword") < 600)
                return notify_fail("��Ľ�����򲻹�������ʩչ" JIU "��\n");

        if ((lvl = (int)me->query_skill("wushang-jianjingsAA", 1)) < 600)
                return notify_fail("������Ͻ����������������޷�ʹ��" JIU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        message_sort(HIM "\n$N" HIM "�������Ͻ�������ؼ�����·�Ի������У�"
                     HIM "�������Ͻ��޾�ѧ" JIU HIM "��\n" NOR, me, target);

        ap = me->query_skill("sword") + me->query_skill("wushang-jianjingsAA", 1) + me->query_skill("wushang-jianjingsAA", 1);
        dp = target->query_skill("dodge") + target->query_skill("parry");

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;

                message_sort(HIW "\n$N" HIW "����������Ю����֮�����ӿ�����$n"
                             HIW "����������\n" NOR, me, target);

                if (ap * 3 / 2 + random(ap) > dp)
                {
                        damage = me->query_skill("force");
                        if (me->query_temp("weapon"))
                        {
                                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, (i + 1) * 3 ,
                                                          HIR "���$n" HIR "����������$N" HIR
                                                          "�Ľ�����������룬$n��ͷһ�����һ��"
                                                          "����Ѫ��\n" NOR);
                        } else
                        {
                                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, (i + 1) * 3,
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
        me->add("neili", -2500 - random(500));
        return 1;
}


