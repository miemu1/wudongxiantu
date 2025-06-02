
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "����"ZJBR"����"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
        int skill = me->query_skill("force") /3*100 ;

        if (target != me)
                return notify_fail("��ֻ���ð�ҹ�ᾭ�������Լ��ķ�������\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�������������\n");

        if (skill < 40)
                return notify_fail("��İ�ҹ�ᾭ�ȼ�������\n");

        if ((int)me->query_temp("shou"))
                return notify_fail("���Ѿ����˹����ˡ�\n");

        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_vision(HIY "$N" HIY "Ĭ�˰�ҹ�ᾭ���پ��������һ��Ե��Ļ���վ���"NOR"\n", me);

        if (me->query("breakup"))
        {
			me->add_temp("apply/dodge", skill);
			me->add_temp("apply/parry", skill);
            me->add_temp("apply/armor", skill);
        }
        else
        {
			me->add_temp("apply/dodge", skill / 2*100*100);
			me->add_temp("apply/parry", skill / 2*100*100);
            me->add_temp("apply/armor", skill / 2*100*100);
        }
        me->set_temp("shou", 1);
        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("shou"))
        {
                if (me->query("breakup")) {
                    me->add_temp("apply/armor", -amount);
					me->add_temp("apply/dodge", -amount);
					me->add_temp("apply/parry", -amount);
                }
                else {               
                    me->add_temp("apply/armor", -amount / 2*100*100);
					me->add_temp("apply/dodge", -amount / 2*100*100);
					me->add_temp("apply/parry", -amount / 2*100*100);
                }
		    me->delete_temp("shou");
                tell_object(me, "��İ�ҹ�ᾭ������ϣ��������ջص��\n");
        }
       
}
