#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define JIU "��" HIW "��תǬ��" NOR "��"


int perform(object me, object target)
{
        string msg;
        int count;
        int lvl, damage;
        int i, ap, dp;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/yinyang-shiertian/jiu"))
                return notify_fail("����δ������Ǭ�����磬����ʩչ" JIU "��\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query("neili") < 900)
                return notify_fail("��������������޷�ʩչ" JIU "��\n");

        if (me->query("max_neili") < 9000)
                return notify_fail("���������Ϊ��������ʹ��" JIU "��\n");

        if ((int)me->query_skill("force") < 800)
                return notify_fail("����ڹ���򲻹�������ʩչ" JIU "��\n");

        if ((lvl = (int)me->query_skill("yinyang-shiertian", 1)) < 800)
                return notify_fail("���̫ʼ�۾��������������޷�ʹ��" JIU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        message_sort(HIM "\n$N" HIM "����̫ʼ�۾����·��������������ʣ�"
                     HIM "�������Ͼ�ѧ" JIU HIM "��\n" NOR, me, target);

        ap = me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("yinyang-shiertian", 1);

        for (i = 0; i < 9; i++)
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
                                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, (i + 1) * 10 ,
                                                          HIR "���$n" HIR "����������$N" HIR
                                                          "���ھ���������룬$n��ͷһ�����һ��"
                                                          "����Ѫ��\n" NOR);
                        } else
                        {
                                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, (i + 1) * 10,
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

        me->start_busy(3 + random(4));
        me->add("neili", -1000 - random(1000));
        return 1;
}


