// shield.c ������

#include <ansi.h>

inherit F_CLEAN_UP;
string query_name() { return "���"ZJBR"���"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("��ֻ������ȿ�ս���������Լ��ķ�������\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("chiyou-kuangzhanjue", 1) < 50)
                return notify_fail("�����ȿ�ս����Ϊ������\n");

        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIW "$N" HIW "ͻȻ��Хһ������ʱȫ���������ģ�"
                        "����������ͭǽ����һ�㣡\n" NOR, me);


        me->add_temp("apply/armor", skill / 10);
        me->set_temp("shield", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("shield"))
        {
                me->add_temp("apply/armor", -amount);
                me->delete_temp("shield");
                tell_object(me, "�����ȿ�ս��������ϣ��������ջص��\n");
        }
}

