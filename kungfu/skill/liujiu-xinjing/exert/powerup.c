#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);
string query_name() { return "��ʮ��"ZJBR"����"; }
int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("��ֻ������ʮ���ľ��������Լ���ս������\n");

        if( me->query_temp("powerup") )
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");

        message_combatd(HIG "\n$N" HIG "�������������������а�������޹���\n" NOR, me);

        // ��ͨBREAKUP���Ч������20%
                if (me->query("breakup"))
        {    
                me->add_temp("apply/attack", skill * 2);
				me->add_temp("apply/damage", skill*2);
				me->add_temp("apply/parry", skill);
				me->add_temp("apply/dodge", skill);
                me->set_temp("powerup", 1);
        }
        else
        {
                me->add_temp("apply/attack", skill);
				me->add_temp("apply/damage", skill);
                me->set_temp("powerup", 1);
        }

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill :), skill);
      
        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("powerup"))
        {
                if (me->query("breakup"))
                {
                        me->add_temp("apply/attack", - (amount * 2));
						me->add_temp("apply/damage", -(amount)*2);
						me->add_temp("apply/parry",  - amount);
						me->add_temp("apply/dodge",  - amount);
                }
                else
                {
                        me->add_temp("apply/attack", - amount);
						me->add_temp("apply/damage", -amount);
                }
                me->delete_temp("powerup");
                tell_object(me, HIY "��������ľ�[��ʮ������]������ϣ��������ջص��\n" NOR);
        }


}