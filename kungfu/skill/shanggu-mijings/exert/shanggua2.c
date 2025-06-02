
#include <ansi.h>

inherit F_CLEAN_UP;

string query_name() { return "[������]"ZJBR"�������"; }
string *pfm_type() { return ({ "force", }); }

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        //int skill, amount;
        int skill;

        if (target != me)
                return notify_fail("��ֻ�����Ϲ��ؾ��������Լ���ս������\n");

        if ((int)me->query("neili") < 10000)
                return notify_fail("�������������\n");

        if ((int)me->query("qi") < 10000)
                return notify_fail("�����Ѫ������\n");

        if ((int)me->query_temp("gong"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -10000);
        me->add("qi", -10000);
        me->receive_damage("qi", 0);

        message_combatd(HIR "$N" HIR "Ĭ���Ϲ��ؾ����پ�һ�ɻ�����ص����������ڷ���Ҵܡ�\n" NOR, me);
        //��ͨ�ζ�������Ч��
        
        if (me->query("breakup"))
        {    
                me->add_temp("apply/attack", skill * 2 / 5*25*25);
				me->add_temp("apply/unarmed_damage", skill/5*25*25);
                me->set_temp("gong", 1);
        }
        else
        {
                me->add_temp("apply/attack", skill / 5*25*25);
				me->add_temp("apply/unarmed_damage", skill/5*25*25);
                me->set_temp("gong", 1);
        }
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("gong"))
        {
                if (me->query("breakup"))
                {
                        me->add_temp("apply/attack", - (amount * 2 / 5*25*25));
						me->add_temp("apply/unarmed_damage", -amount/5*25*25);
                }
                else
                {
                        me->add_temp("apply/attack", - (amount / 5*25*25));
						me->add_temp("apply/unarmed_damage", -amount/5*25*25);
                }
                me->delete_temp("gong");
                tell_object(me, "����Ϲ��ؾ�������ϣ��������ջص��\n");
        }

}


