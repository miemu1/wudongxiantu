#include <ansi.h>

inherit F_SSERVER;

#define LIAN "��" HIW "��������ʮ����" NOR "��"
 string query_name() { return "��������"ZJBR"ʮ����"; }
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

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "ʹ������̫�ܵ۾��ľ�����" HIW "��������ʮ����" HIY"����������Ȼ�ӿ죬գ�ۼ䣬������ʮ������\n" NOR;

        message_combatd(msg, me);
        me->add("neili", -1);

        count = me->query_skill("blade") * 500 / 1;
        me->add_temp("apply/damage", count);

        for (i = 0; i < 12; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/damage", -count);
        me->start_busy(1 + random(1));
        return 1;
}