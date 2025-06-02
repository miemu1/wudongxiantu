// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define PO "��" MAG "һŭɱ��" NOR "��"
string query_name() { return "һŭ"ZJBR"ɱ��"; }
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
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("nuquan", 1) < 40)
                return notify_fail("���ŭȭ������죬�޷�ʩչ" PO "��\n");
                                
        if ((int)me->query("neili") < 200)
                return notify_fail("�����������������޷�ʩչ" PO "��\n");

        if (me->query_skill_prepared("cuff") != "nuquan")
                return notify_fail("��û��׼��ʹ��ŭȭ���޷�ʩչ" PO "��\n");

        if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "ȭ����â��ʹȭ���ס�ȭ����硢ȭ������ȭ���ݷ��������ڣ��ݺݴ��$n" 
              HIY "���ӡ������š�ζ���������\n" NOR;
		ap = me->query_skill("cuff");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("cuff");

                me->add("neili", -120);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 75,
                                           HIR "��ʱ$n" HIR "���ش���Ӱ�죬ֻ��$N" HIR "��һȭ��$n" HIR
                                           "���˳�ȥ�����ص�ˤ�ڵ��ϣ���Ѫ��ֹ��\n" NOR);
                me->start_busy(2);
        } else 
        {
                msg += HIC "����$p" HIC "�����мܣ�Ӳ�����ĵ�����$P"
                       HIC "��һ�С�\n"NOR;
                me->add("neili", -80);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

