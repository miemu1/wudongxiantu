#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("moshen-zhenshen", 1) < 100)
                return notify_fail("���ħ��������Ϊ������\n");

        if ((int)me->query_temp("moshenzhenshen"))
                return notify_fail("���Ѿ�����ħ����������޷������ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIY "$N" HIY "Ĭ��ħ�����ھ��������ڿ��ٵ���ת����ʱ�������γ�һ�������\n" NOR, me);

        me->add_temp("apply/armor", skill / 4);
        me->add_temp("apply/defense", skill / 4);
        me->set_temp("moshenzhenshen", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("moshenzhenshen"))
        {
                me->add_temp("apply/armor", -(amount / 4));
                me->add_temp("apply/defense", -(amount / 4));
                me->delete_temp("moshenzhenshen");
                tell_object(me, "���ħ����������޷�����������ϣ��������ջص��\n");
        }
}
