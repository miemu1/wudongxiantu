#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define JIU "��" HIW "�ɷ����������" NOR "��"

string query_name() { return "[�ɷ�]"ZJBR"�������"; }

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
			
        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        message_sort(HIM "\n$N" HIM "���������淨����ؼ�����·�Ի������У�"
                     HIM "�����ɷ����������" JIU HIM "��\n" NOR, me, target);

        ap = me->query_skill("sword") + me->query_skill("xiuxian-gongfas", 1) + me->query_skill("xiuxian-gongfas", 1);
        dp = target->query_skill("dodge") + target->query_skill("parry");

        for (i = 0; i < 9; i++)
        {
                if (! me->is_fighting(target))
                        break;

                message_sort(HIW "\n$N" HIW "�������ɣ�Ю���֮�����ӿ�����$n"
                             HIW "����������\n" NOR, me, target);

                if (ap * 7 / 2 + random(ap) > dp)
                {
                        damage = me->query_skill("force");
                        if (me->query_temp("weapon"))
                        {
                                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, (i + 1) * 25 ,
                                                          HIR "���$n" HIR "����������$N" HIR
                                                          "�Ľ�����������룬$n��ͷһ�����һ��"
                                                          "����Ѫ��\n" NOR);
                        } else
                        {
                                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, (i + 1) * 25,
                                                          HIR "���$n" HIR "����������$N" HIR
                                                          "�Ľ�����������룬$n��ͷһ�����һ��"
                                                          "����Ѫ��\n" NOR);
                        }
                } else
                {
                        msg = CYN "$n" CYN "����˫�ۣ������мܣ���"
                              "$N" CYN "�Ľ���ж����\n" NOR;
                }

                message_sort(msg, me, target);

                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(1);
        }

        me->start_busy(1 + random(1));
        me->add("neili", -1 - random(5000));
        return 1;
}


