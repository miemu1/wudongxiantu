#include <ansi.h>

inherit F_SSERVER;

#define LIAN "��" HIW "���������������" NOR "��"
 string query_name() { return "��������"ZJBR"�������"; }
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;
        int count;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "sword" )
                return notify_fail("��ʹ�õ��������ԣ�\n");

        if( me->query("neili")<10000 )
                return notify_fail("��������������޷�ʩչ" LIAN "��\n");

        if ((int)me->query_skill("force") < 600)
                return notify_fail("����ڹ���򲻹�������ʩչ" LIAN "��\n");

        if ((int)me->query_skill("shanggu-mijing", 1) < 600)
                return notify_fail("����Ϲ��ؾ������������ң��޷�ʩչ" LIAN "��\n");

        if (me->query_skill_mapped("sword") != "shanggu-mijing")
                return notify_fail("��û�м����Ϲ��ؾ����޷�ʩչ" LIAN "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "ʹ���Ϲ��ؾ��ľ�����" HIW "���������������" HIY"����������Ȼ�ӿ죬գ�ۼ䣬�ӳ��˶�ʮ����\n" NOR;

        message_combatd(msg, me);
        me->add("neili", -10000);

        count = me->query_skill("sword") * 25 / 3;
        me->add_temp("apply/damage", count);

        for (i = 0; i < 20; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/damage", -count);
        me->start_busy(2 + random(3));
        return 1;
}