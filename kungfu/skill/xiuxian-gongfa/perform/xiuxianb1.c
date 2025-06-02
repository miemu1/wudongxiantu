#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define JIU "��" HIW "�ɷ�����������" NOR "��"

string query_name() { return "�ɷ�"ZJBR"��������"; }

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

        if ((int)me->query("neili") < 10000)
                return notify_fail("��������������޷�ʩչ" JIU "��\n");

        if (me->query("max_neili") < 10000)
                return notify_fail("���������Ϊ��������ʹ��" JIU "��\n");

        if ((lvl = (int)me->query_skill("xiuxian-gongfa", 1)) < 150)
                return notify_fail("��������淨�������������޷�ʹ��" JIU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        message_sort(HIM "\n$N" HIM "���������淨���·��������������ʣ�"
                     HIM "�������Ͼ�ѧ" JIU HIM "��\n" NOR, me, target);

        ap = me->query_skill("cuff") + me->query_skill("xiuxian-gongfa", 1) + me->query_skill("xiuxian-gongfa", 1);
        dp = target->query_skill("dodge") + target->query_skill("parry");

        for (i = 0; i < 3; i++)
        {
                if (! me->is_fighting(target))
                        break;

                message_sort(HIW "\n$N" HIW "����������Ю����֮�����ӿ�����$n"
                             HIW "����������\n" NOR, me, target);

                if (ap * 25 / 2 + random(ap) > dp)
                {
                        damage = me->query_skill("cuff");
                        if (me->query_temp("weapon"))
                        {
                                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, (i + 1) * 15 ,
                                                          HIR "���$n" HIR "����������$N" HIR
                                                          "���ھ���������룬$n��ͷһ�����һ��"
                                                          "����Ѫ��\n" NOR);
                        } else
                        {
                                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, (i + 1) * 15,
                                                          HIR "���$n" HIR "����������$N" HIR
                                                          "���ھ���������룬$n��ͷһ�����һ��"
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

        me->start_busy(1 + random(1));
        me->add("neili", -1000 - random(1000));
        return 1;
}


