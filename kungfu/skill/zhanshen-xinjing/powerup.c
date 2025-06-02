// This program is a part of NITAN MudLIB

#include <ansi.h>
string query_name() { return "ս��"ZJBR"ɱ��"; }
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
 
        if( target != me ) 
                return notify_fail("��ֻ��ս���ľ��������Լ���ս������\n");

        if( (int)me->query("neili") < 200  ) 
                return notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -100);

        message_vision(
        HIR "$N����Ϣ��������ս���ľ���ֻ��һ��������������\n" NOR, me);

        me->add_temp("apply/attack", skill * 2 / 3);
        me->add_temp("apply/defense", skill * 2 / 3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill * 2 / 3 :), skill/5);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if( (int)me->query_temp("powerup") ) 
        {
                me->add_temp("apply/attack", - amount);
                me->add_temp("apply/defense", - amount);
                me->delete_temp("powerup");
                tell_object(me, "���ս���ľ�������ϣ��������ջص��\n");
        }
}


