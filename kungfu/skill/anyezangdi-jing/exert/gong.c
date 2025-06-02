
#include <ansi.h>

inherit F_CLEAN_UP;

string query_name() { return "����"ZJBR"����"; }
string *pfm_type() { return ({ "force", }); }

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        //int skill, amount;
        int skill;

        if (target != me)
                return notify_fail("��ֻ���ð�ҹ�ᾭ�������Լ���ս������\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_temp("gong"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIR "$N" HIR "Ĭ�˰�ҹ�ᾭ���پ�һ�ɻ�����ص����������ڷ���Ҵܡ�\n" NOR, me);
        //��ͨ�ζ�������Ч��
        
        if (me->query("breakup"))
        {    
                me->add_temp("apply/attack", skill * 2 / 3*100*100);
				me->add_temp("apply/unarmed_damage", skill/4*100*100);
                me->set_temp("gong", 1);
        }
        else
        {
                me->add_temp("apply/attack", skill / 3*100*100);
				me->add_temp("apply/unarmed_damage", skill/6*100*100);
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
                        me->add_temp("apply/attack", - (amount * 2 / 3*100*100));
						me->add_temp("apply/unarmed_damage", -amount/4*100*100);
                }
                else
                {
                        me->add_temp("apply/attack", - (amount / 3*100*100));
						me->add_temp("apply/unarmed_damage", -amount/6*100*100);
                }
                me->delete_temp("gong");
                tell_object(me, "��İ�ҹ�ᾭ������ϣ��������ջص��\n");
        }

}


