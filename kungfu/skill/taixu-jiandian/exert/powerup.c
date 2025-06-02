// powerup.c ̫�齣������

#include <ansi.h>

inherit F_CLEAN_UP;
string query_name() { return "̫��"ZJBR"����"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("��ֻ����̫�齣���������Լ���ս������\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_temp("powerup"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIC "$N" HIC "�ľ��ں�Ϊֹˮ���ľ����Ϊ�޳���"
						"�ı�͸��Ϊ��������������Ϊ̫��\n" NOR, me);

        me->add_temp("apply/attack", skill );
        me->add_temp("apply/parry", skill );
        me->add_temp("apply/dodge", skill );
		me->add_temp("apply/sword", skill );
		me->add_temp("apply/unarmed_damage", skill );
		me->add_temp("apply/damage", skill );
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("powerup"))
        {
                me->add_temp("apply/attack", - (amount ));
                me->add_temp("apply/parry", - (amount ));
                me->add_temp("apply/dodge", - (amount ));
				me->add_temp("apply/sword", -(amount ));
				me->add_temp("apply/unarmed_damage", -(amount ) );
				me->add_temp("apply/damage", -(amount ));
                me->delete_temp("powerup");
                tell_object(me, "���̫�齣��������ϣ��������ջص��\n");
        }
}

