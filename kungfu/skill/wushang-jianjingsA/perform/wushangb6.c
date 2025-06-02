#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

#define TIAN "��" HIY "һ��һɱ" NOR "��"



////////////////////////////////////////
//1  �ж�����
//2  �ж���������
//3  �жϷ�ѧ����ѧ����
//4  �жϽ�������
//5  �ж��������
//6  �жϺ��������unarmed
//7  �ж���������
//8  �жϺ������Լ�literate
//9  �ж��������
//10 �жϺ�����Ǽ�force
//11 �ж�������
//12 �жϺ�������dodge
///////////////////////////////////////

string query_name() { return "һ��"ZJBR"һɱ"; }

string final(object me, object target, int damage);

int perform(object me, object target)
{
        int damage, damage1;
        int p;
        string msg, cl, wp;
        int ap, dp, dp1;
        int lvl;
        object weapon, cloth;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(TIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("force", 1) < 600)
                return notify_fail("���ڹ���Ϊ����������ʩչ" TIAN "��\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("��������Ϊ����������ʩչ" TIAN "��\n");

        if ((int)me->query("max_jingli") < 2000)
                return notify_fail("�㾫����Ϊ����������ʩչ" TIAN "��\n");

        lvl = (int)me->query_skill("wushang-jianjingsAA", 1);
        if (lvl < 100)
                return notify_fail("�����Ͻ�����򲻹�������ʩչ" TIAN "��\n");

        if ((int)me->query("neili") < 2000)
                return notify_fail("��������������������ʩչ" TIAN "��\n");

        if (me->query_skill("sword-cognize", 1) < 150)
                return notify_fail("����ѧ�������㣬����ʩչ" TIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        message_sort(HIM "\n$N" HIM "����Ĭ�����޳����������һ��һɱ��"
                     "���ռ��ƺ�ҲŤ����������$n" HIM "��ʧɫ���·���������磡\n" NOR, me, target);


        ap = me->query_skill("force");

        damage = target->query_skill("force");

        if (me->query_temp("weapon"))
        {
				damage += me->query_temp("apply/damage");
        } else
        {
                damage += me->query_temp("apply/unarmed_damage");
        }

        dp = target->query_skill("dodge") + target->query_skill("wushang-jianjingsAA", 1);

        // ��һ�У��ж϶Է�����
        message_sort(HIW "$N" HIW "˫��һ��һ�ɻ���������ھ���ӿ���ȣ�"
                     "������ɽ����֮����$n" HIW "ϯ�������\n" NOR, me, target);

        damage1 = 0;

        if (ap * 10 / 3 + random(ap) > dp)
        {
                if (me->query("max_neili") > target->query("max_neili") * 3)
                {
                        msg = HIW "$n" HIW "�ٱ�����,Ȼ��$N" HIW "���������޿ɵ�����"
                              "ɲ�Ǽ�ͽ�$n" HIW "ȫ���ͷѹ�顣" NOR "( $n" RED "���˹��أ���"
                              "��������в�����ʱ�����ܶ�����" NOR ")\n";
                        damage1 = -1;
                        me->add("neili", -1000);
                } else
                {
                        target->receive_damage("qi", 2000-target->query("jianman"), me);
				      target->receive_wound("qi", 2000-target->query("jianman"), me);
                        p = (int)target->query("qi") * 125 / (int)target->query("max_qi");

                        msg = HIY "$n" HIY "˼��δ����$N" HIY "���ھ���������룬"
                              "$n" HIY "�ܴ��ػ������һ��Ż������" HIR "��Ѫ" HIY "��\n" NOR;
                        msg += "( $n" + eff_status_msg(p) + " )\n";

                        me->add("neili", -500);
                }
        } else
        {
                msg = CYN "$n" CYN "֪��$N�����޿ɵֵ���"
                       CYN "��������Ծ����������������\n" NOR;
                me->add("neili", -1500);
        }
        message_sort(msg, me, target);



        me->start_busy(3);
        me->add("neili", -1000 - random(500));
        return 1;
}

string final(object me, object target, int ap)
{
        target->add_temp("apply/avoid_busy", -90);
        target->add_temp("apply/reduce_busy", -36);
        target->add_temp("apply/avoid_weak", -90);
        target->add_temp("apply/avoid_locked", -90);
        target->set_temp("no_perform", 1, target);
        remove_call_out("tian_end");
        call_out("tian_end", 10 + random(ap / 50), me, target);
        return HIY "$n" HIY "˿���������а��һ�����񣬵��������ش���\n" NOR +
               WHT "$n" WHT "�е�����ĺ�������������æ�ҡ����Ӿ����䶳��������ӡ��\n" NOR;
}

void tian_end(object me, object target)
{
        if( target && target->query_temp("no_perform") )
        {
                if (living(target))
                {
                        message_combatd(HIC "$N" HIC "��������һ��"
                                        "������ɫ�ɰ�ת�죬��������"
                                        "���ˡ�\n" NOR, target);

                        tell_object(target, HIY "��е������ҵ�����"
                                            "����ƽ����������\n" NOR);
                }
        target->add_temp("apply/avoid_busy", 90);
        target->add_temp("apply/reduce_busy", 36);
        target->add_temp("apply/avoid_weak", 90);
        target->add_temp("apply/avoid_locked", 90);
        tell_object(target, HIR "��ĺ�������������æ�ҡ����Ӿ����䶳�������ڽ����ӡ��\n" NOR);
                target->delete_temp("no_perform");
        }
        return;
}