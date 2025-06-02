
#include <ansi.h>

inherit F_CLEAN_UP;
string query_name() { return "����"ZJBR"����"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("��ֻ���������ľ��������Լ���ս������\n");

        if( me->query_temp("shield") )
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");

        message_combatd(HIR "$N" HIR "Ĭ�������ľ����������Ʋ��ɴ��⡣\n" NOR, me);

        // ��ͨBREAKUP���Ч�����ӷ���
        if (me->query("breakup"))
        {    
                me->add_temp("apply/armor", skill * 2);
			//	me->add_temp("apply/parry", skill);
                me->set_temp("shield", 1);
        }
        else
        {
                me->add_temp("apply/armor", skill);
			//	me->add_temp("apply/parry", skill/2);
                me->set_temp("shield", 1);
        }

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill :), skill );

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("powerup"))
        {
                if (me->query("breakup"))
                {
                        me->add_temp("apply/armor", - (amount * 2 ));
					//	me->add_temp("apply/parry", -(amount));
                }
                else
                {
                        me->add_temp("apply/armor", - amount);
					//	me->add_temp("apply/parry", -amount/2);
                }

                me->delete_temp("shield");
                tell_object(me, HIW "��������ľ��������塹������ϣ��������ջص��\n" NOR);
        }


}